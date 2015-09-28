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


#define DEF_TITLE_Y (400.0f)
#define DEF_LABEL_Y (200.0f)
#define DEF_LABEL_Y_MARGIN (70.0f)
#define DEF_LABEL_ANCHOR (Vec2(0,0))
#define DEF_NAME_X (30.0f)
#define DEF_BEFORE_X (300.0f)
#define DEF_AFTER_X (450.0f)

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
                                  visibleSize.height/2 + origin.y + DEF_TITLE_Y));
    
    this->addChild(titleSprite, 10);
    this->m_roll = RollBackgroundLayer::create();
    this->addChild(this->m_roll,0);
    this->m_roll->setPosition(Vec2::ZERO);
    
    //----------------
    //メニュー
    //----------------
    
    this->m_ValuePoint = Label::createWithBMFont("str/little_number.fnt","000000000 p");

    float UpLabelPosY = visibleSize.height/2 + origin.y + DEF_LABEL_Y;
    
    //ノーマルショットパワーアップ
    this->m_LabelBaseMaxPower = Sprite::create("str/label_shot_power.png");
    this->m_ValueBaseMaxPowerBefore = Label::createWithBMFont("str/little_number.fnt","001 p");
    this->m_ValueBaseMaxPowerAfter = Label::createWithBMFont("str/little_number.fnt","001 p");
    this->addChild(this->m_LabelBaseMaxPower,10);
    this->addChild(this->m_ValueBaseMaxPowerBefore,10);
    this->addChild(this->m_ValueBaseMaxPowerAfter,10);
    this->m_LabelBaseMaxPower->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_ValueBaseMaxPowerBefore->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_ValueBaseMaxPowerAfter->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_LabelBaseMaxPower->setPosition(DEF_NAME_X,UpLabelPosY);
    this->m_ValueBaseMaxPowerBefore->setPosition(DEF_BEFORE_X,UpLabelPosY);
    this->m_ValueBaseMaxPowerAfter->setPosition(DEF_AFTER_X,UpLabelPosY);
    
    UpLabelPosY -= DEF_LABEL_Y_MARGIN;
    
    //連射時間
    this->m_LabelShotCycle = Sprite::create("str/label_shot_cycle.png");
    this->m_ValueShotCycleBefore = Label::createWithBMFont("str/little_number.fnt","1.50sec");
    this->m_ValueShotCycleAfter = Label::createWithBMFont("str/little_number.fnt","1.50sec");
    this->addChild(this->m_LabelShotCycle,10);
    this->addChild(this->m_ValueShotCycleBefore,10);
    this->addChild(this->m_ValueShotCycleAfter,10);
    this->m_LabelShotCycle->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_ValueShotCycleBefore->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_ValueShotCycleAfter->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_LabelShotCycle->setPosition(DEF_NAME_X,UpLabelPosY);
    this->m_ValueShotCycleBefore->setPosition(DEF_BEFORE_X,UpLabelPosY);
    this->m_ValueShotCycleAfter->setPosition(DEF_AFTER_X,UpLabelPosY);
    
    UpLabelPosY -= DEF_LABEL_Y_MARGIN;

    //チャージショット最大パワー
    this->m_LabelChargePower = Sprite::create("str/label_charge_power.png");
    this->m_ValueChargePowerBefore = Label::createWithBMFont("str/little_number.fnt","001 p");
    this->m_ValueChargePowerAfter = Label::createWithBMFont("str/little_number.fnt","001 p");
    this->addChild(this->m_LabelChargePower,10);
    this->addChild(this->m_ValueChargePowerBefore,10);
    this->addChild(this->m_ValueChargePowerAfter,10);
    this->m_LabelChargePower->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_ValueChargePowerBefore->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_ValueChargePowerAfter->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_LabelChargePower->setPosition(DEF_NAME_X,UpLabelPosY);
    this->m_ValueChargePowerBefore->setPosition(DEF_BEFORE_X,UpLabelPosY);
    this->m_ValueChargePowerAfter->setPosition(DEF_AFTER_X,UpLabelPosY);
    
    UpLabelPosY -= DEF_LABEL_Y_MARGIN;
    
    //チャージ時間
    this->m_LabelChargeTime = Sprite::create("str/label_charge_time.png");
    this->m_ValueChargeTimeBefore = Label::createWithBMFont("str/little_number.fnt","1.50 sec");
    this->m_ValueChargeTimeAfter = Label::createWithBMFont("str/little_number.fnt","1.50 sec");
    this->addChild(this->m_LabelChargeTime,10);
    this->addChild(this->m_ValueChargeTimeBefore,10);
    this->addChild(this->m_ValueChargeTimeAfter,10);
    this->m_LabelChargeTime->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_ValueChargeTimeBefore->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_ValueChargeTimeAfter->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_LabelChargeTime->setPosition(DEF_NAME_X,UpLabelPosY);
    this->m_ValueChargeTimeBefore->setPosition(DEF_BEFORE_X,UpLabelPosY);
    this->m_ValueChargeTimeAfter->setPosition(DEF_AFTER_X,UpLabelPosY);

    UpLabelPosY -= DEF_LABEL_Y_MARGIN;
    
    //プレイヤーHP
    this->m_LabelPlayerLife = Sprite::create("str/label_player_life.png");
    this->m_ValuePlayerLifeBefore = Label::createWithBMFont("str/little_number.fnt","");
    this->m_ValuePlayerLifeAfter = Label::createWithBMFont("str/little_number.fnt","");
    this->addChild(this->m_LabelPlayerLife,10);
    this->addChild(this->m_ValuePlayerLifeBefore,10);
    this->addChild(this->m_ValuePlayerLifeAfter,10);
    this->m_LabelPlayerLife->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_ValuePlayerLifeBefore->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_ValuePlayerLifeAfter->setAnchorPoint(DEF_LABEL_ANCHOR);
    this->m_LabelPlayerLife->setPosition(DEF_NAME_X,UpLabelPosY);
    this->m_ValuePlayerLifeBefore->setPosition(DEF_BEFORE_X,UpLabelPosY);
    this->m_ValuePlayerLifeAfter->setPosition(DEF_AFTER_X,UpLabelPosY);
    
    
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
