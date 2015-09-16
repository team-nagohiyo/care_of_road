//
//  BulletObject.cpp
//  care_of_road
//
//  Created by ooharayukio on 2015/09/16.
//
//

#include "BulletObject.h"

USING_NS_CC;

BulletObject::BulletObject()
{
    
}
BulletObject::~BulletObject()
{
    
}
BulletObject* BulletObject::create(int charaId)
{
    BulletObject * ret = nullptr;
    ret = new BulletObject();
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
bool BulletObject::init(int charaId)
{
    if(!Node::init())
    {
        return false;
    }
    
    
    
    return true;
}
