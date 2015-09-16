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
protected:
    cocos2d::LayerColor * m_normal;
    cocos2d::LayerColor * m_charge;
    cocos2d::EventListenerTouchOneByOne * m_Listener;
public:
    CREATE_FUNC(TouchControlLayer);
    virtual bool init();
    TouchControlLayer();
    virtual ~TouchControlLayer();
    
    bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
};

#endif /* defined(__care_of_road__TouchControlLayer__) */
