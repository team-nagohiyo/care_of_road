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
#include "BulletObject.h"

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
        Hit,
        DeadBody,
        Soul,
    };
    
    //弾モード
    enum struct ShotMode : int
    {
        MachineGun,
        ChageShot,
    };
    CC_SYNTHESIZE(int, m_Type, Type);
    CC_SYNTHESIZE(int, m_Score, Score);
    CC_SYNTHESIZE(int, m_Life, Life);
    CC_SYNTHESIZE(PlayerState, State, State);
    
    CC_SYNTHESIZE(int, m_ChargeMaxPower, ChargeMaxPower);
    CC_SYNTHESIZE(int, m_ChargeAdd, ChargeAdd);
    
protected:
    cocos2d::Sprite * m_mainSprite;
    
    float m_ChagePower;
    float m_Delay;
    ShotMode m_Mode;
public:
    PlayerObject();
    virtual ~PlayerObject();
    static PlayerObject* create();
    virtual bool init();

    /**
     * 行動の更新
     */
    virtual void update(float dt);
    
    /**
     * 弾の発射
     */
    virtual void OnMashinGun();
    
    /**
     * 弾の溜め
     */
    virtual void OnChage();
    
    /**
     * 弾の生成
     */
    virtual BulletObject * createBullet();
    
};


#endif /* defined(__care_of_road__PlayerObject__) */