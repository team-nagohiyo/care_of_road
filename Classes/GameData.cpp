//
//  GameData.cpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/16.
//
//

#include "GameData.h"

USING_NS_CC;

GameData * GameData::getInstance()
{
    static GameData instance;
    return &instance;
}
/**
 * スコアの取得
 */
int GameData::getHighScore()
{
    return UserDefault::getInstance()->getIntegerForKey("HighScore", 0);
}
/**
 * スコアの設定
 */
void GameData::setHighScore(int val)
{
     UserDefault::getInstance()->setIntegerForKey("HighScore", val);
}
