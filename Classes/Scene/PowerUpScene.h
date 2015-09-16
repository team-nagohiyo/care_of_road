//
//  PowerUpScene.h
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/16.
//
//

#ifndef __care_of_road__PowerUpScene__
#define __care_of_road__PowerUpScene__

#include "cocos2d.h"
#include "RollBackgroundLayer.h"

class PowerUpScene : public cocos2d::Layer
{
protected:
    RollBackgroundLayer * m_roll;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(PowerUpScene);
    
    /**
     * タイトル画面に移動
     */
    void moveToTitle(cocos2d::Ref * sender);
};


#endif /* defined(__care_of_road__PowerUpScene__) */
