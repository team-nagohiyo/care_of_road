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
    
    
    
    return true;
}
