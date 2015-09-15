//
//  GameData.cpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/16.
//
//

#include "GameData.h"

GameData * GameData::getInstance()
{
    static GameData instance;
    return &instance;
}
