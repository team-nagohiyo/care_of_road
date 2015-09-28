//
//  GameOverScene.cpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/22.
//
//

#include "GameOverScene.h"
#include "GameData.h"
#include "GameScene.h"
#include "PowerUpScene.h"
#include "RankingScene.h"
#include "TitleScene.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* GameOverScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameOverScene::create();
    scene->addChild(layer);
    return scene;
}
bool GameOverScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto titleSprite = Sprite::create("str/title_game_over.png");
    // position the sprite on the center of the screen
    titleSprite->setPosition(Vec2(visibleSize.width/2 + origin.x,
                                  visibleSize.height/2 + origin.y + 300.0f));
    
    this->addChild(titleSprite, 10);
    
    this->m_roll = RollBackgroundLayer::create();
    this->addChild(this->m_roll,0);
    this->m_roll->setPosition(Vec2::ZERO);
    
    //メニュー
    auto labelScore = Sprite::create("str/label_score.png");
    labelScore->setPosition(Vec2(origin.x + visibleSize.width/2,
                                 origin.y + visibleSize.height * 0.625f));
    this->addChild(labelScore, 3);
    char strScore[32] = "";
    sprintf(strScore,"%012d",GameData::getInstance()->getGameScore());
    
    //ハイスコアへの登録
    if(GameData::getInstance()->getHighScore() > GameData::getInstance()->getGameScore())
    {
        GameData::getInstance()->setHighScore(GameData::getInstance()->getGameScore());
    }
    
    auto label = Label::createWithBMFont("str/little_number.fnt",strScore);
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height/2));
    this->addChild(label, 2);
    
    auto gameItem = MenuItemImage::create("str/menu_retry.png", "str/menu_retry.png");
    gameItem->setCallback(CC_CALLBACK_1(GameOverScene::moveToGame, this));
    gameItem->setPosition(Vec2(visibleSize.width/2 + origin.x,
                               visibleSize.width/2 + origin.y - 50.0f));
    
    auto powerUpItem = MenuItemImage::create("str/menu_power_up.png", "str/menu_power_up.png");
    powerUpItem->setCallback(CC_CALLBACK_1(GameOverScene::moveToPowrUp, this));
    powerUpItem->setPosition(Vec2(visibleSize.width/2 + origin.x,
                                  visibleSize.width/2 + origin.y - 100.0f));
    
    auto rankingItem = MenuItemImage::create("str/menu_ranking.png", "str/menu_ranking.png");
    rankingItem->setCallback(CC_CALLBACK_1(GameOverScene::moveToRanking, this));
    rankingItem->setPosition(Vec2(visibleSize.width/2 + origin.x,
                                  visibleSize.width/2 + origin.y - 150.0f));
    
    auto topItem = MenuItemImage::create("str/menu_top_menu.png", "str/menu_top_menu.png");
    topItem->setCallback(CC_CALLBACK_1(GameOverScene::moveToTitle, this));
    topItem->setPosition(Vec2(visibleSize.width/2 + origin.x,
                                  visibleSize.width/2 + origin.y - 200.0f));
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(gameItem, powerUpItem,rankingItem,topItem,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    return true;
}
/**
 * ゲーム画面に移動
 */
void GameOverScene::moveToGame(Ref * sender)
{
    SimpleAudioEngine::getInstance()->playEffect("sound/cow_jingle_start.mp3");
    Director::getInstance()->replaceScene(GameScene::createScene());
}
/**
 * パワーアップ画面に移動
 */
void GameOverScene::moveToPowrUp(Ref * sender)
{
    Director::getInstance()->replaceScene(PowerUpScene::createScene());
}
/**
 * ランキング画面に移動
 */
void GameOverScene::moveToRanking(Ref * sender)
{
    Director::getInstance()->replaceScene(RankingScene::createScene());
}
/**
 * タイトル画面に移動
 */
void GameOverScene::moveToTitle(cocos2d::Ref * sender)
{
    Director::getInstance()->replaceScene(TitleScene::createScene());
}
