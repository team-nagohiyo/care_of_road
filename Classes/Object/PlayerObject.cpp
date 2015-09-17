//
//  PlayerObject.cpp
//  care_of_road
//
//  Created by ooharayukio on 2015/09/16.
//
//

#include "PlayerObject.h"
#include "GameData.h"

USING_NS_CC;

PlayerObject::PlayerObject()
{
    
}
PlayerObject::~PlayerObject()
{
    
}
PlayerObject* PlayerObject::create()
{
    PlayerObject * ret = nullptr;
    ret = new PlayerObject();
    if(ret && ret->init())
    {
        ret->autorelease();
        return ret;
    }
    else
    {
        delete ret;
        ret = nullptr;
    }
    return ret;
}
bool PlayerObject::init()
{
    if(!HitObject::init())
    {
        return false;
    }
    this->m_mainSprite = Sprite::create("game/turtle.png");
    
    
    this->addChild(this->m_mainSprite);
    this->setContentSize(this->m_mainSprite->getContentSize());
    this->setAnchorPoint(Vec2::ONE * 0.5f);
    
    this->m_mainSprite->setPosition(this->getContentSize()/2.0f);
    
    this->setChargeMaxPower(5);
    this->setChargeAdd(1);
    this->m_ChagePower = 0;
    this->m_Delay = 0;
    return true;
}

/**
 * 行動の更新
 */
void PlayerObject::update(float dt)
{
    if(!this->getHitObjectList().empty())
    {
        this->setState(PlayerState::Hit);
        this->m_ChagePower = 0;
    }

    if(this->m_Delay < 0)
    {
        //charge中ステートの処理
        if(this->m_Mode == ShotMode::ChageShot)
        {
            if(this->getState() == PlayerState::Charge)
            {
                this->setState(PlayerState::Charge);
                
                if(this->m_ChagePower > this->getChargeMaxPower())
                {
                    this->m_ChagePower = 0;
                    
                    this->createBullet();
                }
                else
                {
                    this->m_ChagePower += this->getChargeAdd() * dt;
                }
            }
        }
        else
        {
            this->createBullet();
        }
    }
    else
    {
        this->setState(PlayerState::Delay);
    }
}

/**
 * 弾の発射
 */
void PlayerObject::OnMashinGun()
{
    this->m_Mode = ShotMode::MachineGun;
}

/**
 * 弾の溜め
 */
void PlayerObject::OnChage()
{
    this->m_Mode = ShotMode::ChageShot;
}

/**
 * 弾の生成
 */
BulletObject * PlayerObject::createBullet()
{
    
}

