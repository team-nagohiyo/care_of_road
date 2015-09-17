//
//  GameScene.cpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/16.
//
//

#include "GameScene.h"
#include "GameData.h"
#include "GameMediator.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;
GameScene::GameScene()
{
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
    
    
    this->m_roll = RollBackgroundLayer::create();
    this->addChild(this->m_roll,0);
    this->m_roll->setPosition(Vec2::ZERO);
    
    //メニュー
    
    this->m_EnemyLayer = Layer::create();
    this->m_EnemyLayer->setPosition(Vec2::ZERO);
    this->addChild(this->m_EnemyLayer,10);

    this->m_BulletLayer = Layer::create();
    this->m_BulletLayer->setPosition(Vec2::ZERO);
    this->addChild(this->m_BulletLayer,20);
    
    this->m_PlayerObject = PlayerObject::create();
    this->m_PlayerObject->setPosition(Vec2(visibleSize.width * 0.5f,200.0f));
    this->addChild(this->m_PlayerObject,30);
    
    GameData::getInstance()->setGameScore(0);
    
    //更新の開始
    this->scheduleUpdate();
    
    this->m_TouchControl = TouchControlLayer::create();
    this->m_TouchControl->setPosition(origin);
    this->m_TouchControl->setBeganCallback(CC_CALLBACK_2(GameScene::OnControlTapBegan,this));
    this->m_TouchControl->setMovedCallback(CC_CALLBACK_2(GameScene::OnControlTapMoved,this));
    this->m_TouchControl->setEndedCallback(CC_CALLBACK_2(GameScene::OnControlTapEnded,this));
    this->addChild(this->m_TouchControl,1);
    
    this->m_createDelay = 0.0f;
    
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
        for(auto work : this->m_BulletList)
        {
            float range = work->getHitLength() + target->getHitLength();
            if((work->getPosition() - target->getPosition()).length() < range)
            {
                target->entryHitObject(work);
                work->entryHitObject(target);
            }
        }
        
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
    this->m_createDelay -= dt;

    //敵の行動
    for(auto work : this->m_EnemyList)
    {
        work->setPositionY(work->getPositionY() - this->m_roll->getSpeed() * dt);
    }
    //弾の行動
    for(auto work : this->m_BulletList)
    {
        work->updateAction(dt);
    }
    
    //プレイヤーの行動
    this->m_PlayerObject->update(dt);

    
    //敵の生成
    if(this->m_createDelay < 0.0f)
    {
        this->m_createDelay = 1.0f;
        auto enemy = EnemyObject::create(0);
        float workX = this->getContentSize().width - enemy->getContentSize().width;
        workX = random(0.0f, workX) + (enemy->getContentSize().width / 2.0f);
        float workY = 1500.0f;
        enemy->setPosition(Vec2(workX,workY));
        GameMediator::getInstance()->entryEnemyObjectToField(enemy);
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
 * コントローラのタップ移動
 */
void GameScene::OnControlTapMoved(cocos2d::Vec2 pos,TouchControlLayer::TapType type)
{
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
 * コントローラのタップ終了
 */
void GameScene::OnControlTapEnded(cocos2d::Vec2 pos,TouchControlLayer::TapType type)
{
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

