//
//  EnemyObject.cpp
//  care_of_road
//
//  Created by ooharayukio on 2015/09/16.
//
//

#include "EnemyObject.h"

USING_NS_CC;

EnemyObject::EnemyObject()
{
    
}
EnemyObject::~EnemyObject()
{
    
}
EnemyObject* EnemyObject::create(int charaId)
{
    EnemyObject * ret = nullptr;
    ret = new EnemyObject();
    if(ret && ret->init(charaId))
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
bool EnemyObject::init(int charaId)
{
    if(!Node::init())
    {
        return false;
    }
    this->m_mainSprite = nullptr;
    switch (charaId) {
        default:
        case 0:
            m_mainSprite = Sprite::create("game/enemy.png");
            break;
    }

    
    this->addChild(this->m_mainSprite);
    this->setContentSize(this->m_mainSprite->getContentSize());
    this->setAnchorPoint(Vec2::ONE * 0.5f);
    
    this->m_mainSprite->setPosition(this->getContentSize()/2.0f);
    return true;
}
