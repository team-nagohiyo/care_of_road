//
//  GameScene.cpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/16.
//
//

#include "GameScene.h"
#include "GameOverScene.h"
#include "GameData.h"
#include "GameMediator.h"
#include "EnemyGenerator.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;
GameScene::GameScene()
:m_State(GameState::StartWait)
{
    //仲介クラスに登録する
    GameMediator::getInstance()->setMediateGameScene(this);
}
GameScene::~GameScene()
{
    GameMediator::getInstance()->setMediateGameScene(nullptr);
}

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}
bool GameScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    

    //背景の動く床
    this->m_roll = RollBackgroundLayer::create();
    this->addChild(this->m_roll,0);
    this->m_roll->setPosition(Vec2::ZERO);

    //敵の配置レイヤー
    this->m_EnemyLayer = Layer::create();
    this->m_EnemyLayer->setPosition(Vec2::ZERO);
    this->addChild(this->m_EnemyLayer,10);

    //弾の配置レイヤー
    this->m_BulletLayer = Layer::create();
    this->m_BulletLayer->setPosition(Vec2::ZERO);
    this->addChild(this->m_BulletLayer,20);
    
    this->m_PlayerObject = PlayerObject::create();
    this->m_StartingPos = Vec2(visibleSize.width * 0.5f,200.0f);
    this->m_StartPos = Vec2(visibleSize.width * 0.5f,-128.0f);
    this->m_PlayerObject->setPosition(m_StartPos);
    this->addChild(this->m_PlayerObject,30);
    
    //メニュー
    auto labelScore = Sprite::create("str/label_score.png");
    labelScore->setPosition(Vec2(origin.x + 10.0f + labelScore->getContentSize().width * 0.5f,
                                 origin.y + visibleSize.height
                                 - 10.0f - labelScore->getContentSize().height * 0.5f));
    this->addChild(labelScore, 50);
    
    this->m_ScoreLabel = Label::createWithBMFont("str/little_number.fnt","");
    this->m_ScoreLabel->setPosition(Vec2(origin.x + labelScore->getContentSize().width + 20.0f,
                            labelScore->getPositionY()));
    this->m_ScoreLabel->setAnchorPoint(Vec2(0.0f,0.5f));
    this->addChild(this->m_ScoreLabel, 60);
    
    //
    this->refreshScoreLabel();
    
    GameData::getInstance()->setGameScore(0);
    
    EnemyGenerator::getInstance()->setGeneratePosition(Vec2(this->getContentSize().width * 0.5f,1500.0f));
    EnemyGenerator::getInstance()->setGenerateWidth(this->getContentSize().width);
    
    //更新の開始
    this->scheduleUpdate();
    
    this->m_TouchControl = TouchControlLayer::create();
    this->m_TouchControl->setPosition(origin);
    this->m_TouchControl->setBeganCallback(CC_CALLBACK_2(GameScene::OnControlTapBegan,this));
    this->m_TouchControl->setMovedCallback(CC_CALLBACK_2(GameScene::OnControlTapMoved,this));
    this->m_TouchControl->setEndedCallback(CC_CALLBACK_2(GameScene::OnControlTapEnded,this));
    this->addChild(this->m_TouchControl,1);
    
    this->m_TouchRect.setRect(origin.x, origin.y,
                              this->m_TouchControl->getContentSize().width,
                              this->m_TouchControl->getContentSize().height);
    
    return true;
}
/**
 * 更新
 */
void GameScene::update(float dt)
{
    //ヒットチェック
    this->hitCheck();
    
    //オブジェクト行動
    this->updateAction(dt);
    
    //オブジェクトデリートチェック
    this->removeObjectWithSoul();
    
}
/**
 * ヒットチェック
 */
void GameScene::hitCheck()
{
    for(auto target : this->m_EnemyList)
    {
        if(false == target->getEnabled())continue;
        
        for(auto work : this->m_BulletList)
        {
            if(false == work->getEnabled())continue;
            float range = work->getHitLength() + target->getHitLength();
            if((work->getPosition() - target->getPosition()).length() < range)
            {
                target->entryHitObject(work);
                work->entryHitObject(target);
            }
        }
        
        if(false == m_PlayerObject->getEnabled())continue;
        float range = this->m_PlayerObject->getHitLength() + target->getHitLength();
        if((this->m_PlayerObject->getPosition() - target->getPosition()).length() < range)
        {
            target->entryHitObject(this->m_PlayerObject);
            this->m_PlayerObject->entryHitObject(target);
        }
    }
}

/**
 * 行動
 */
void GameScene::updateAction(float dt)
{
    if(this->getState() == GameScene::GameState::GamePlay)
    {
        //敵の行動
        for(auto work : this->m_EnemyList)
        {
            work->setPositionY(work->getPositionY() - this->m_roll->getSpeed() * dt);
            work->updateAction(dt);
            
            //スコアの回収
            if(!work->isAlive())
            {
                if(work->getScore() != 0)
                {
                    GameData * ins = GameData::getInstance();
                    ins->setGameScore((ins->getGameScore() - work->getScore()));
                    work->setScore(0);
                }
            }
        }
        //弾の行動
        for(auto work : this->m_BulletList)
        {
            work->updateAction(dt);
        }
        
        //プレイヤーの行動
        this->m_PlayerObject->updateAction(dt);

        //敵生成の更新
        EnemyGenerator::getInstance()->updateSchedule(dt);
        

    }
    //スタート用の処理
    if(this->getState() == GameScene::GameState::Starting)
    {
        Vec2 moveVec = ((this->m_StartingPos - this->m_StartPos) / 1.5f) * dt;
        this->m_PlayerObject->setPosition(this->m_PlayerObject->getPosition() + moveVec);
        if(this->m_PlayerObject->getPosition().y > this->m_StartingPos.y)
        {
            this->m_PlayerObject->setPositionY(this->m_StartingPos.y);
            this->setState(GameState::GamePlay);
        }
    }

    //プレイヤーが死んだらゲームオーバーに移行
    if(!this->m_PlayerObject->isAlive())
    {
        this->setState(GameState::GameOver);
    }
    
    if(this->getState() == GameState::GameOver)
    {
        this->moveToGameOver();
    }
}

/**
 * 魂状態の人を削除
 */
void GameScene::removeObjectWithSoul()
{

    //弾のデリートチェック
    cocos2d::Vector<BulletObject*> deleteList;
    for(auto work : this->m_BulletList)
    {
        if(work->getAttack() <= 0 ||
           work->getPositionY() > (work->getContentSize().height + this->getContentSize().height))
        {
            this->m_BulletLayer->removeChild(work);
            deleteList.pushBack(work);
        }
    }
    for(auto work : deleteList)
    {
        this->m_BulletList.eraseObject(work);
    }
    deleteList.clear();
    
    //敵のデリートチェック
    cocos2d::Vector<EnemyObject*> deleteList2;
    for(auto work : this->m_EnemyList)
    {
        if(work->getState() == EnemyObject::EnemyState::SOUL ||
           work->getPositionY() < -work->getContentSize().height)
        {
            this->m_EnemyLayer->removeChild(work);
            deleteList2.pushBack(work);
        }
    }
    for(auto work : deleteList2)
    {
        this->m_EnemyList.eraseObject(work);
    }
    deleteList2.clear();
    
    
}

/**
 * 敵オブジェクトの追加
 */
void GameScene::entryEnemyObject(EnemyObject* obj)
{
    this->m_EnemyList.pushBack(obj);
    this->m_EnemyLayer->addChild(obj);
}

/**
 * 弾オブジェクトの追加
 */
void GameScene::entryBulletObject(BulletObject* obj)
{
    this->m_BulletList.pushBack(obj);
    this->m_BulletLayer->addChild(obj);
}

/**
 * コントローラのタップ開始
 */
void GameScene::OnControlTapBegan(cocos2d::Vec2 pos,TouchControlLayer::TapType type)
{
    if(this->getState() == GameState::GamePlay)
    {
        this->sharedTapControl(pos, type);
    }
}
/**
 * コントローラのタップ移動
 */
void GameScene::OnControlTapMoved(cocos2d::Vec2 pos,TouchControlLayer::TapType type)
{
    if(this->getState() == GameState::GamePlay)
    {
        this->sharedTapControl(pos, type);
    }
}
/**
 * コントローラのタップ終了
 */
void GameScene::OnControlTapEnded(cocos2d::Vec2 pos,TouchControlLayer::TapType type)
{
    if(this->getState() == GameScene::GameState::StartWait)
    {
        this->setState(GameState::Starting);
        SimpleAudioEngine::getInstance()->playEffect("sound/cow_jingle_start.mp3");
        
    }
    else if(this->getState() == GameState::GamePlay)
    {
        this->sharedTapControl(pos, type);
    }
}
/**
 * 共通操作処理
 */
void GameScene::sharedTapControl(cocos2d::Vec2 pos,TouchControlLayer::TapType type)
{
    if(m_TouchRect.getMinX() > pos.x)pos.x = m_TouchRect.getMinX();
    if(m_TouchRect.getMaxX() < pos.x)pos.x = m_TouchRect.getMaxX();
    if(m_TouchRect.getMinY() > pos.y)pos.y = m_TouchRect.getMinY();
    if(m_TouchRect.getMaxY() < pos.y)pos.y = m_TouchRect.getMaxY();
    
    this->m_PlayerObject->setPosition(pos);
    
    if(type == TouchControlLayer::TapType::Normal)
    {
        //マシンガン開始
        this->m_PlayerObject->OnMashinGun();
    }
    else
    {
        //charge開始
        this->m_PlayerObject->OnChage();
    }
}

/**
 * スコア表示の更新
 */
void GameScene::refreshScoreLabel()
{
    char strScore[32] = "";
    sprintf(strScore,"%012d",GameData::getInstance()->getHighScore());
    this->m_ScoreLabel->setString(strScore);
}
/**
 * ゲームオーバー画面に移動
 */
void GameScene::moveToGameOver()
{
    Director::getInstance()->replaceScene(GameOverScene::createScene());
}

