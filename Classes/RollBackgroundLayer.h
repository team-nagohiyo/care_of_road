//
//  RollBackgroundLayer.h
//  care_of_road
//
//  Created by ooharayukio on 2015/09/14.
//
//

#ifndef __care_of_road__RollBackgroundLayer__
#define __care_of_road__RollBackgroundLayer__

#include "cocos2d.h"

/**
 * スクロールする背景
 */
class RollBackgroundLayer : public cocos2d::Layer
{
    
public:
    RollBackgroundLayer();
    virtual ~RollBackgroundLayer();
    CREATE_FUNC(RollBackgroundLayer);
    bool init();
};

#endif /* defined(__care_of_road__RollBackgroundLayer__) */
