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
/**
 * 基本値の読み込み
 */
void GameData::loadSettingData()
{
    //ポイント
    UserDefault::getInstance()->setIntegerForKey("GamePoint", this->m_GamePoint);
    //最大パワー
    UserDefault::getInstance()->setIntegerForKey("MaxPower", this->m_MaxPower);
    //チャージパワー
    UserDefault::getInstance()->setIntegerForKey("ChargePower", this->m_ChargePower);
    //チャージ速度
    UserDefault::getInstance()->setFloatForKey("ChargeTime", this->m_ChargeTime);
    //連射ディレイ
    UserDefault::getInstance()->setFloatForKey("ShotCycle", this->m_ShotCycle);
    //弾の大きさ
    UserDefault::getInstance()->setFloatForKey("ShotSize", this->m_ShotSize);
    //プレイヤーのHP
    UserDefault::getInstance()->setIntegerForKey("PlayerHp", this->m_PlayerHp);
    
}

/**
 * 基本値の保存
 */
void GameData::saveSettingData()
{
    //ポイント
    this->m_GamePoint = UserDefault::getInstance()->getIntegerForKey("GamePoint", 0);
    //最大パワー
    this->m_MaxPower = UserDefault::getInstance()->getIntegerForKey("MaxPower", 1);
    //チャージパワー
    this->m_ChargePower = UserDefault::getInstance()->getIntegerForKey("ChargePower", 1);
    //チャージ速度
    this->m_ChargeTime = UserDefault::getInstance()->getFloatForKey("ChargeTime", 1.5f);
    //連射ディレイ
    this->m_ShotCycle = UserDefault::getInstance()->getFloatForKey("ShotCycle", 1.0f);
    //弾の大きさ
    this->m_ShotSize = UserDefault::getInstance()->getFloatForKey("ShotSize", 1.0f);
    //プレイヤーのHP
    this->m_PlayerHp = UserDefault::getInstance()->getIntegerForKey("PlayerHp", 1);
}

