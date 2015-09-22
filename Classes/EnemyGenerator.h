//
//  EnemyGenerator.hpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/20.
//
//

#ifndef EnemyGenerator_hpp
#define EnemyGenerator_hpp

#include "cocos2d.h"

class EnemyGenerator
{
protected:
    CC_SYNTHESIZE(int, m_Level, Level);
    CC_SYNTHESIZE(int, m_MaxLevel, MaxLevel);
    CC_SYNTHESIZE(float, m_GenerateWidth, GenerateWidth);
    CC_SYNTHESIZE(cocos2d::Vec2, m_GeneratePosition, GeneratePosition);
    
    float m_createDelay;
public:
    EnemyGenerator();
    /**
     * シングルトンinstance
     */
    static EnemyGenerator * getInstance();
    
    /**
     * 生成の更新
     */
    void updateSchedule(float dt);
    
    /**
     * カウントの初期化
     */
    void reset();
};

#endif /* EnemyGenerator_hpp */
