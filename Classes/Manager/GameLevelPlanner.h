//
//  GameLevelPlanner.h
//  care_of_road
//
//  Created by 大原幸夫 on 2015/10/12.
//
//

#ifndef GameLevelPlanner_h
#define GameLevelPlanner_h

#include <stdio.h>

/**
 * プレイ中の変化するレベル条件を管理する
 */
class GameLevelPlanner
{
public:
    GameLevelPlanner();
    virtual ~GameLevelPlanner();
    static GameLevelPlanner * getInstance();
};

#endif /* GameLevelPlanner_h */
