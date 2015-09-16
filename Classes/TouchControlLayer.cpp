//
//  TouchControlLayer.cpp
//  care_of_road
//
//  Created by ooharayukio on 2015/09/16.
//
//

#include "TouchControlLayer.h"

USING_NS_CC;

TouchControlLayer::TouchControlLayer()
{
    
}
TouchControlLayer::~TouchControlLayer()
{
    
}
bool TouchControlLayer::init()
{
    if(!Layer::init())
    {
        return false;
    }

    this->setContentSize(Size(this->getContentSize().width,250.0f));

    this->m_normal = LayerColor::create(Color4B(0x3F,0x3F,0xFF,0x7F), this->getContentSize().width, 125.0f);
    this->m_normal->setPosition(Vec2(0.0f,125.0f));
    this->addChild(this->m_normal);

    this->m_charge = LayerColor::create(Color4B(0xFF,0x3F,0x3F,0x7F), this->getContentSize().width, 125.0f);
    this->m_charge->setPosition(Vec2(0.0f,0.0f));
    this->addChild(this->m_charge);
    
    return true;
}
