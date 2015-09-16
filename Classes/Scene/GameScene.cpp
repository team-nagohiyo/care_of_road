//
//  GameScene.cpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/16.
//
//

#include "GameScene.h"
#include "GameData.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

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
    this->addChild(this->m_EnemyLayer,1);

    this->m_BulletLayer = Layer::create();
    this->m_BulletLayer->setPosition(Vec2::ZERO);
    this->addChild(this->m_BulletLayer,2);
    
    
    GameData::getInstance()->setGameScore(0);
    
    //更新の開始
    this->scheduleUpdate();
    
    return true;
}
/**
 * 更新
 */
void GameScene::update(float dt)
{
    //ヒットチェック
    
    
    //オブジェクト行動
    
    
    //オブジェクトデリートチェック
}

/**
 * 敵オブジェクトの追加
 */
void GameScene::entryEnemyObject(cocos2d::Vec2 position, EnemyObject* obj)
{
    this->m_EnemyList.pushBack(obj);
    this->m_EnemyLayer->addChild(obj);
}

/**
 * 弾オブジェクトの追加
 */
void GameScene::entryBulletObject(cocos2d::Vec2 position, BulletObject* obj)
{
    this->m_BulletList.pushBack(obj);
    this->m_EnemyLayer->addChild(obj);
}
