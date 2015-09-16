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
public:
    CREATE_FUNC(TouchControlLayer);
    virtual bool init();
    TouchControlLayer();
    virtual ~TouchControlLayer();
    
};

#endif /* defined(__care_of_road__TouchControlLayer__) */
