//
//  PlayerObject.h
//  care_of_road
//
//  Created by ooharayukio on 2015/09/16.
//
//

#ifndef __care_of_road__PlayerObject__
#define __care_of_road__PlayerObject__

#include "cocos2d.h"
#include "HitObject.h"

/**
 * プレイヤーのオブジェクト
 */
class PlayerObject : public HitObject
{
public:
    //プレイヤーのステート
    enum struct PlayerState:int
    {
        Wait = 0,
        Shot,
        Delay,
        Charge,
    };
    CC_SYNTHESIZE(int, m_Type, Type);
    CC_SYNTHESIZE(int, m_Score, Score);
    CC_SYNTHESIZE(int, m_Life, Life);
    CC_SYNTHESIZE(PlayerState, State, State);
protected:
    cocos2d::Sprite * m_mainSprite;
    
public:
    PlayerObject();
    virtual ~PlayerObject();
    static PlayerObject* create();
    virtual bool init();
    
};


#endif /* defined(__care_of_road__PlayerObject__) */
