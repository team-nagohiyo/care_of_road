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

    //ポイント
    cocos2d::Sprite * m_LabelPoint;
    cocos2d::Label * m_ValuePoint;
    
    //ノーマルショットパワー
    cocos2d::Sprite * m_LabelBaseMaxPower;
    cocos2d::Label * m_ValueBaseMaxPowerBefore;
    cocos2d::Label * m_ValueBaseMaxPowerAfter;
    
    //連射
    cocos2d::Sprite * m_LabelShotCycle;
    cocos2d::Label * m_ValueShotCycleBefore;
    cocos2d::Label * m_ValueShotCycleAfter;
    
    //チャージパワー
    cocos2d::Sprite * m_LabelChargePower;
    cocos2d::Label * m_ValueChargePowerBefore;
    cocos2d::Label * m_ValueChargePowerAfter;
    
    //チャージ時間
    cocos2d::Sprite * m_LabelChargeTime;
    cocos2d::Label * m_ValueChargeTimeBefore;
    cocos2d::Label * m_ValueChargeTimeAfter;
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
