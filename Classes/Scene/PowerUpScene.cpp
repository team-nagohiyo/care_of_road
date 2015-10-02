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
#define DEF_POINT_Y (300.0f)
#define DEF_LABEL_Y (200.0f)
#define DEF_LABEL_Y_MARGIN (110.0f)
#define DEF_LABEL_Y_LAYER_BOTTOM (10.0f)

#define DEF_LABEL_ANCHOR (cocos2d::Vec2(0,0))
#define DEF_NAME_X (30.0f)
#define DEF_BEFORE_X (280.0f)
#define DEF_AFTER_X (450.0f)

#define DEF_TAPLAYER_RECT_WIDTH (600.0f)
#define DEF_TAPLAYER_RECT_HEIGHT (100.0f)

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
    
    this->m_ValuePoint = Label::createWithBMFont("str/FNT_small_font_y.fnt","000000000 p");
    this->m_ValuePoint->setPosition(Vec2(visibleSize.width/2 + origin.x,
                                  visibleSize.height/2 + origin.y + DEF_POINT_Y));
    
    this->addChild(m_ValuePoint, 10);

    cocos2d::Vector<MenuItem*> menuList;
    
    float UpLabelPosY = visibleSize.height/2 + origin.y + DEF_LABEL_Y;
    
    //ノーマルショットパワーアップ
    this->m_MenuBaseMaxPower = this->makeMenuItemRect(PowerUpItemType::ShotPower);
    this->m_MenuBaseMaxPower->setPosition(Vec2(20.0f,UpLabelPosY));
    menuList.pushBack(this->m_MenuBaseMaxPower);
    
    UpLabelPosY -= DEF_LABEL_Y_MARGIN;
    
    //連射時間
    this->m_MenuShotCycle = this->makeMenuItemRect(PowerUpItemType::ShotCycle);
    this->m_MenuShotCycle->setPosition(Vec2(20.0f,UpLabelPosY));
    menuList.pushBack(this->m_MenuShotCycle);

    UpLabelPosY -= DEF_LABEL_Y_MARGIN;

    //チャージショット最大パワー
    this->m_MenuChargePower = this->makeMenuItemRect(PowerUpItemType::ChargePower);
    this->m_MenuChargePower->setPosition(Vec2(20.0f,UpLabelPosY));
    menuList.pushBack(this->m_MenuChargePower);
    
    UpLabelPosY -= DEF_LABEL_Y_MARGIN;
    
    //チャージ時間
    this->m_MenuChargeTime = this->makeMenuItemRect(PowerUpItemType::ChargeTime);
    this->m_MenuChargeTime->setPosition(Vec2(20.0f,UpLabelPosY));
    menuList.pushBack(this->m_MenuChargeTime);

    UpLabelPosY -= DEF_LABEL_Y_MARGIN;
    
    //プレイヤーHP
    this->m_MenuPlayerLife = this->makeMenuItemRect(PowerUpItemType::PlayerLife);
    this->m_MenuPlayerLife->setPosition(Vec2(20.0f,UpLabelPosY));
    menuList.pushBack(this->m_MenuPlayerLife);
    
    
    auto topMenuItem = MenuItemImage::create("str/menu_top_menu.png", "str/menu_top_menu.png");
    topMenuItem->setCallback(CC_CALLBACK_1(PowerUpScene::moveToTitle, this));
    topMenuItem->setPosition(Vec2(visibleSize.width/2 + origin.x,
                                  visibleSize.width/2 + origin.y - 250.0f));
    menuList.pushBack(topMenuItem);
    
    auto menu = Menu::createWithArray(menuList);
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
/**
 * メニューの作成
 */
cocos2d::MenuItem * PowerUpScene::makeMenuItemRect(PowerUpItemType itemType)
{
    MenuItem * ret = MenuItem::create();
    auto tapRect = LayerColor::create(Color4B(0x00,0x00,0x00,0x7F), DEF_TAPLAYER_RECT_WIDTH, DEF_TAPLAYER_RECT_HEIGHT);
    ret->addChild(tapRect,1);
    cocos2d::Sprite * labelSprite = nullptr;
    cocos2d::Label * Valuelabel = nullptr;
    cocos2d::Label * CostLabel = Label::createWithBMFont("str/FNT_small_font_y.fnt","0000000p");
    
    switch (itemType)
    {
        case PowerUpItemType::ShotPower :
        {
            //ノーマルショットパワーアップ
            this->m_LabelBaseMaxPower = Sprite::create("str/label_shot_power.png");
            labelSprite = this->m_LabelBaseMaxPower;
            this->m_ValueBaseMaxPowerValue = Label::createWithBMFont("str/little_number.fnt","Lv 01");
            Valuelabel = this->m_ValueBaseMaxPowerValue;
            this->m_ValueBaseMaxPowerCost = CostLabel;
        }
            break;
        case PowerUpItemType::ShotCycle :
        {
            //連射時間
            this->m_LabelShotCycle = Sprite::create("str/label_shot_cycle.png");
            labelSprite = this->m_LabelShotCycle;
            this->m_ValueShotCycleValue = Label::createWithBMFont("str/little_number.fnt","1.50 sec");
            Valuelabel = this->m_ValueShotCycleValue;
            this->m_ValueShotCycleCost = CostLabel;
        }
            break;
        case PowerUpItemType::ChargePower :
        {
            //チャージショット最大パワー
            this->m_LabelChargePower = Sprite::create("str/label_charge_power.png");
            labelSprite = this->m_LabelChargePower;
            this->m_ValueChargePowerValue = Label::createWithBMFont("str/little_number.fnt","Lv 01");
            Valuelabel = this->m_ValueChargePowerValue;
            this->m_ValueChargePowerCost = CostLabel;
        }
            break;
        case PowerUpItemType::ChargeTime :
        {
            //チャージ時間
            this->m_LabelChargeTime = Sprite::create("str/label_charge_time.png");
            labelSprite = this->m_LabelChargeTime;
            this->m_ValueChargeTimeValue = Label::createWithBMFont("str/little_number.fnt","1.50 sec");
            Valuelabel = this->m_ValueChargeTimeValue;
            this->m_ValueChargeTimeCost = CostLabel;
        }
            break;
        case PowerUpItemType::PlayerLife :
        {
            //プレイヤーHP
            this->m_LabelPlayerLife = Sprite::create("str/label_player_life.png");
            labelSprite = this->m_LabelPlayerLife;
            this->m_ValuePlayerLifeValue = Label::createWithBMFont("str/little_number.fnt","Life 1");
            Valuelabel = this->m_ValuePlayerLifeValue;
            this->m_ValuePlayerLifeCost = CostLabel;
        }
            break;
        default:
            break;
    }
    
    labelSprite->setAnchorPoint(DEF_LABEL_ANCHOR);
    labelSprite->setPosition(DEF_NAME_X,DEF_LABEL_Y_LAYER_BOTTOM);
    tapRect->addChild(labelSprite);
    Valuelabel->setAnchorPoint(DEF_LABEL_ANCHOR);
    Valuelabel->setPosition(DEF_BEFORE_X,DEF_LABEL_Y_LAYER_BOTTOM);
    tapRect->addChild(Valuelabel);
    CostLabel->setAnchorPoint(DEF_LABEL_ANCHOR);
    CostLabel->setPosition(DEF_AFTER_X,DEF_LABEL_Y_LAYER_BOTTOM);
    tapRect->addChild(CostLabel);
    
    
    return ret;
}
/**
 * メニューの数値更新
 */
void PowerUpScene::updateValue()
{
    
}

