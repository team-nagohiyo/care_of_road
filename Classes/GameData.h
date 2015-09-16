//
//  GameData.h
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/16.
//
//

#ifndef __care_of_road__GameData__
#define __care_of_road__GameData__

#include "cocos2d.h"

class GameData
{
    
    //移動量
    CC_SYNTHESIZE(float, m_GroundHeightMove, GroundHeightMove);
    //Gameスコア
    CC_SYNTHESIZE(int, m_GameScore, GameScore);
public:
    static GameData * getInstance();
    
    /**
     * スコアの取得
     */
    int getHighScore();
    /**
     * スコアの設定
     */
    void setHighScore(int val);
};

#endif /* defined(__care_of_road__GameData__) */
