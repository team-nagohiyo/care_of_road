//
//  GameLevelPlanner.cpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/10/12.
//
//

#include "GameLevelPlanner.h"

GameLevelPlanner::GameLevelPlanner()
{
    
}
GameLevelPlanner::~GameLevelPlanner()
{
    
}

GameLevelPlanner * GameLevelPlanner::getInstance()
{
    static GameLevelPlanner instance;
    return &instance;
}
