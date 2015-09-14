//
//  TitleScene.cpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/14.
//
//

#include "TitleScene.h"

USING_NS_CC;

Scene* TitleScene::createScene()
{
    auto scene = Scene::create();
    auto layer = TitleScene::create();
    scene->addChild(layer);
    return scene;
}
bool TitleScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto titleSprite = Sprite::create("str/logo_care_of_way.png");
    // position the sprite on the center of the screen
    titleSprite->setPosition(Vec2(visibleSize.width/2 + origin.x,
                                  visibleSize.height/2 + origin.y + 300.0f));
    
    this->addChild(titleSprite, 10);

    this->m_roll = RollBackgroundLayer::create();
    this->addChild(this->m_roll,2);
    this->m_roll->setPosition(Vec2::ZERO);
    
    //メニュー

    
    return true;
}