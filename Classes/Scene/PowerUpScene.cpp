//
//  PowerUpScene.cpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/16.
//
//

#include "PowerUpScene.h"
#include "TitleScene.h"
#include "GameData.h"

USING_NS_CC;

Scene* PowerUpScene::createScene()
{
    auto scene = Scene::create();
    auto layer = PowerUpScene::create();
    scene->addChild(layer);
    return scene;
}
bool PowerUpScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto titleSprite = Sprite::create("str/title_power_up.png");
    // position the sprite on the center of the screen
    titleSprite->setPosition(Vec2(visibleSize.width/2 + origin.x,
                                  visibleSize.height/2 + origin.y + 300.0f));
    
    this->addChild(titleSprite, 10);
    this->m_roll = RollBackgroundLayer::create();
    this->addChild(this->m_roll,0);
    this->m_roll->setPosition(Vec2::ZERO);
    
    //----------------
    //メニュー
    //----------------
    
    this->m_ValuePoint = Label::createWithBMFont("str/little_number.fnt","000000000 p");

    //ノーマルショットパワーアップ
    this->m_ValueShotCycleBefore = Label::createWithBMFont("str/little_number.fnt","001 p");
    this->m_ValueShotCycleAfter = Label::createWithBMFont("str/little_number.fnt","001 p");
    
    //連射時間
    this->m_ValueShotCycleBefore = Label::createWithBMFont("str/little_number.fnt","1.50sec");
    this->m_ValueShotCycleAfter = Label::createWithBMFont("str/little_number.fnt","1.50sec");
    
    //チャージショット最大パワー
    this->m_ValueChargePowerBefore = Label::createWithBMFont("str/little_number.fnt","001 p");
    this->m_ValueChargePowerAfter = Label::createWithBMFont("str/little_number.fnt","001 p");
    
    //チャージ時間
    this->m_ValueChargeTimeBefore = Label::createWithBMFont("str/little_number.fnt","1.50 sec");
    this->m_ValueChargeTimeAfter = Label::createWithBMFont("str/little_number.fnt","1.50 sec");

    //プレイヤーHP
    this->m_ValueShotCycleAfter = Label::createWithBMFont("str/little_number.fnt","");
    this->m_ValueShotCycleBefore = Label::createWithBMFont("str/little_number.fnt","");
    
    
    auto topMenuItem = MenuItemImage::create("str/menu_top_menu.png", "str/menu_top_menu.png");
    topMenuItem->setCallback(CC_CALLBACK_1(PowerUpScene::moveToTitle, this));
    topMenuItem->setPosition(Vec2(visibleSize.width/2 + origin.x,
                                  visibleSize.width/2 + origin.y - 250.0f));
    auto menu = Menu::create(topMenuItem,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return true;
}
/**
 * タイトル画面に移動
 */
void PowerUpScene::moveToTitle(cocos2d::Ref * sender)
{
    Director::getInstance()->replaceScene(TitleScene::createScene());    
}
