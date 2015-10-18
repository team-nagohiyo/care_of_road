//
//  GameData.cpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/16.
//
//

#include "GameData.h"

USING_NS_CC;

#define DEF_DEFAULT_MAX_POWER (1)
#define DEF_DEFAULT_CHARGE_POWER (1)
#define DEF_DEFAULT_CHARGE_TIME (1.5f)
#define DEF_DEFAULT_SHOT_CYCLE (1.0f)
#define DEF_DEFAULT_SHOT_SIZE (1.0f)
#define DEF_DEFAULT_PLAYER_HP (1)

#define DEF_ADD_MAX_POWER (1)
#define DEF_ADD_CHARGE_POWER (1)
#define DEF_ADD_CHARGE_TIME (1.5f)
#define DEF_ADD_SHOT_CYCLE (1.0f)
#define DEF_ADD_SHOT_SIZE (1.0f)
#define DEF_ADD_PLAYER_HP (1)


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
    this->m_GamePoint = UserDefault::getInstance()->getIntegerForKey("GamePoint", 0);
    if(this->m_GamePoint < 0)this->m_GamePoint = 0;
    //最大パワー
    this->m_BaseMaxPower = UserDefault::getInstance()->getIntegerForKey("MaxPower", 1);
    if(this->m_BaseMaxPower < 1)this->m_BaseMaxPower = 1;
    //チャージパワー
    this->m_ChargePower = UserDefault::getInstance()->getIntegerForKey("ChargePower", 1);
    if(this->m_ChargePower < 1)this->m_ChargePower = 1;
    //チャージ速度
    this->m_ChargeTime = UserDefault::getInstance()->getFloatForKey("ChargeTime", 1.5f);
    if(this->m_ChargeTime < 1.5f)this->m_ChargeTime = 1.5f;
    //連射ディレイ
    this->m_ShotCycle = UserDefault::getInstance()->getFloatForKey("ShotCycle", 1.0f);
    if(this->m_ShotCycle < 1.0f)this->m_ShotCycle = 1.0f;
    //弾の大きさ
    this->m_ShotSize = UserDefault::getInstance()->getFloatForKey("ShotSize", 1.0f);
    if(this->m_ShotSize < 1.0f)this->m_ShotSize = 1.0f;
    //プレイヤーのHP
    this->m_PlayerHp = UserDefault::getInstance()->getIntegerForKey("PlayerHp", 1);
    if(this->m_PlayerHp < 1)this->m_PlayerHp = 1;
}

/**
 * 基本値の保存
 */
void GameData::saveSettingData()
{
    //ポイント
    UserDefault::getInstance()->setIntegerForKey("GamePoint", this->m_GamePoint);
    //最大パワー
    UserDefault::getInstance()->setIntegerForKey("MaxPower", this->m_BaseMaxPower);
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
 * デバック用デフォルトリセット
 */
void GameData::resetdefaultValue()
{
    
}
//---------------------
//default値
//---------------------
/**
 * 最大パワー
 */
int GameData::getDefaultValueBaseMaxPower()
{
    return DEF_DEFAULT_MAX_POWER;
}
/**
 * チャージパワー
 */
int GameData::getDefaultValueChargePower()
{
    return DEF_DEFAULT_CHARGE_POWER;
}
/**
 * チャージ速度
 */
int GameData::getDefaultValueChargeTime()
{
    return DEF_DEFAULT_CHARGE_TIME;
}
/**
 * 連射ディレイ
 */
int GameData::getDefaultValueShotCycle()
{
    return DEF_DEFAULT_SHOT_CYCLE;
}
/**
 * 弾の大きさ
 */
int GameData::getDefaultValueShotSize()
{
    return DEF_DEFAULT_SHOT_SIZE;
}
/**
 * プレイヤーのHP
 */
int GameData::getDefaultValuePlayerHp()
{
    return DEF_DEFAULT_PLAYER_HP;
}

//---------------------
//加算値
//---------------------
/**
 * 最大パワー
 */
int GameData::getAddValueBaseMaxPower()
{
    return DEF_ADD_MAX_POWER;
}
/**
 * チャージパワー
 */
int GameData::getAddValueChargePower()
{
    return DEF_ADD_CHARGE_POWER;
}
/**
 * チャージ速度
 */
int GameData::getAddValueChargeTime()
{
    return DEF_ADD_CHARGE_TIME;
}
/**
 * 連射ディレイ
 */
int GameData::getAddValueShotCycle()
{
    return DEF_ADD_SHOT_CYCLE;
}
/**
 * 弾の大きさ
 */
int GameData::getAddValueShotSize()
{
    return DEF_ADD_SHOT_SIZE;
}
/**
 * プレイヤーのHP
 */
int GameData::getAddValuePlayerHp()
{
    return DEF_ADD_PLAYER_HP;
}


