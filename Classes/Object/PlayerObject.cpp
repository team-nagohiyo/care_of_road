//
//  PlayerObject.cpp
//  care_of_road
//
//  Created by ooharayukio on 2015/09/16.
//
//

#include "PlayerObject.h"

USING_NS_CC;

PlayerObject::PlayerObject()
{
    
}
PlayerObject::~PlayerObject()
{
    
}
PlayerObject* PlayerObject::create()
{
    PlayerObject * ret = nullptr;
    ret = new PlayerObject();
    if(ret && ret->init())
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        delete ret;
        ret = nullptr;
    }
    return ret;
}
bool PlayerObject::init()
{
    if(!HitObject::init())
    {
        return false;
    }
    this->m_mainSprite = Sprite::create("game/turtle.png");
    
    
    this->addChild(this->m_mainSprite);
    this->setContentSize(this->m_mainSprite->getContentSize());
    this->setAnchorPoint(Vec2::ONE * 0.5f);
    
    this->m_mainSprite->setPosition(this->getContentSize()/2.0f);
    return true;
}
