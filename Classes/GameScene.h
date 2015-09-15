//
//  GameScene.h
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/16.
//
//

#ifndef __care_of_road__GameScene__
#define __care_of_road__GameScene__

#include "cocos2d.h"
#include "RollBackgroundLayer.h"

class GameScene : public cocos2d::Layer
{
protected:
    RollBackgroundLayer * m_roll;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(GameScene);
};

#endif /* defined(__care_of_road__GameScene__) */
