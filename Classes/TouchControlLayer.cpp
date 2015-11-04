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
    auto normalLabel = Label::createWithBMFont("str/FNT_value_s.fnt", "Normal Area");
    this->m_normal->addChild(normalLabel);
    normalLabel->setAnchorPoint(Vec2(0,1));
    normalLabel->setPosition(Vec2(0,this->m_normal->getContentSize().height * 0.5f));

    this->m_charge = LayerColor::create(Color4B(0xFF,0x3F,0x3F,0x7F), this->getContentSize().width, 125.0f);
    this->m_charge->setPosition(Vec2(0.0f,0.0f));
    this->addChild(this->m_charge);
    auto chargeLabel = Label::createWithBMFont("str/FNT_value_s.fnt", "Charge Area");
    this->m_charge->addChild(chargeLabel);
    chargeLabel->setAnchorPoint(Vec2(0,1));
    chargeLabel->setPosition(Vec2(0,this->m_charge->getContentSize().height * 0.5f));
    
    this->m_Listener = EventListenerTouchOneByOne::create();
    this->m_Listener->setSwallowTouches(true);
    this->m_Listener->onTouchBegan = CC_CALLBACK_2(TouchControlLayer::onTouchBegan, this);
    this->m_Listener->onTouchMoved = CC_CALLBACK_2(TouchControlLayer::onTouchMoved, this);
    this->m_Listener->onTouchEnded = CC_CALLBACK_2(TouchControlLayer::onTouchEnded, this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(this->m_Listener, this);

    
    return true;
}

bool TouchControlLayer::onTouchBegan(Touch *touch, Event *unused_event)
{
    Vec2 world = this->m_normal->getParent()->convertToWorldSpace(this->m_normal->getPosition());
    this->m_NormalRect = Rect(world.x,world.y,this->m_normal->getContentSize().width,this->m_charge->getContentSize().height);

     world = this->m_charge->getParent()->convertToWorldSpace(this->m_charge->getPosition());
    this->m_ChargeRect = Rect(world.x,world.y,this->m_charge->getContentSize().width,this->m_charge->getContentSize().height);
    

    TapType type = TapType::None;
    Vec2 pos = touch->getLocation();
    if(pos.x < 0)pos.x = 0;
    if(pos.y < 0)pos.y = 0;
    if(this->m_NormalRect.containsPoint(pos))type = TapType::Normal;
    else if(this->m_ChargeRect.containsPoint(pos))type = TapType::Charge;
    if(this->m_BeganCallback)this->m_BeganCallback(pos,type);
    
    return true;
}

void TouchControlLayer::onTouchMoved(Touch *touch, Event *unused_event)
{
    Vec2 world = this->m_normal->getParent()->convertToWorldSpace(this->m_normal->getPosition());
    this->m_NormalRect = Rect(world.x,world.y,this->m_normal->getContentSize().width,this->m_normal->getContentSize().height);
    
    world = this->m_charge->getParent()->convertToWorldSpace(this->m_charge->getPosition());
    this->m_ChargeRect = Rect(world.x,world.y,this->m_charge->getContentSize().width,this->m_charge->getContentSize().height);
    
    
    TapType type = TapType::None;
    Vec2 pos = touch->getLocation();
    if(pos.x < 0)pos.x = 0;
    if(pos.y < 0)pos.y = 0;
    if(this->m_NormalRect.containsPoint(pos))type = TapType::Normal;
    else if(this->m_ChargeRect.containsPoint(pos))type = TapType::Charge;
    if(this->m_MovedCallback)this->m_MovedCallback(pos,type);
    
}

void TouchControlLayer::onTouchEnded(Touch *touch, Event *unused_event)
{
    Vec2 world = this->m_normal->getParent()->convertToWorldSpace(this->m_normal->getPosition());
    this->m_NormalRect = Rect(world.x,world.y,this->m_normal->getContentSize().width,this->m_normal->getContentSize().height);
    
    world = this->m_charge->getParent()->convertToWorldSpace(this->m_charge->getPosition());
    this->m_ChargeRect = Rect(world.x,world.y,this->m_charge->getContentSize().width,this->m_charge->getContentSize().height);
    
    
    TapType type = TapType::None;
    Vec2 pos = touch->getLocation();
    if(pos.x < 0)pos.x = 0;
    if(pos.y < 0)pos.y = 0;
    if(this->m_NormalRect.containsPoint(pos))type = TapType::Normal;
    else if(this->m_ChargeRect.containsPoint(pos))type = TapType::Charge;
    if(this->m_EndedCallback)this->m_EndedCallback(pos,type);
}