//
//  TouchControlLayer.h
//  care_of_road
//
//  Created by ooharayukio on 2015/09/16.
//
//

#ifndef __care_of_road__TouchControlLayer__
#define __care_of_road__TouchControlLayer__

#include "cocos2d.h"

class TouchControlLayer : public cocos2d::Layer
{
public:
    enum struct TapType:int
    {
        None = 0,
        Normal,
        Charge
    };
protected:
    cocos2d::LayerColor * m_normal;
    cocos2d::LayerColor * m_charge;
    cocos2d::EventListenerTouchOneByOne * m_Listener;
    
    cocos2d::Rect m_NormalRect;
    cocos2d::Rect m_ChargeRect;
    
    std::function<void (cocos2d::Vec2,TapType)> m_BeganCallback;
    std::function<void (cocos2d::Vec2,TapType)> m_MovedCallback;
    std::function<void (cocos2d::Vec2,TapType)> m_EndedCallback;
    
public:
    CREATE_FUNC(TouchControlLayer);
    virtual bool init();
    TouchControlLayer();
    virtual ~TouchControlLayer();
    
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
    virtual void setBeganCallback(std::function<void (cocos2d::Vec2,TapType)> func)
    {
        this->m_BeganCallback = func;
    }
    virtual void setMovedCallback(std::function<void (cocos2d::Vec2,TapType)> func)
    {
        this->m_MovedCallback = func;
    }
    virtual void setEndedCallback(std::function<void (cocos2d::Vec2,TapType)> func)
    {
        this->m_EndedCallback = func;
    }
};

#endif /* defined(__care_of_road__TouchControlLayer__) */
