//
//  EnemyGenerator.cpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/20.
//
//

#include "EnemyGenerator.h"
#include "EnemyObject.h"
#include "GameMediator.h"

USING_NS_CC;

EnemyGenerator::EnemyGenerator()
{
    
}
/**
 * シングルトンinstance
 */
EnemyGenerator * EnemyGenerator::getInstance()
{
    static EnemyGenerator instance;
    return &instance;
}

/**
 * ジェネレート
 */
void EnemyGenerator::updateSchedule(float dt)
{
    this->m_createDelay -= dt;
    
    //敵の生成
    if(this->m_createDelay < 0.0f)
    {
        auto enemy = EnemyObject::create(0);
        float workX = this->getGeneratePosition().x;
        float workY = this->getGeneratePosition().y;
        float width = this->getGenerateWidth() - enemy->getContentSize().width;
        workX += (random(0.0f, width) + (enemy->getContentSize().width / 2.0f) - workX);
        enemy->setPosition(Vec2(workX,workY));
        GameMediator::getInstance()->entryEnemyObjectToField(enemy);
        
        //仮で生成レベルのコントロール
        this->setMakeCount(this->getMakeCount()+ 1);
        if(0 == this->getMakeCount()%10 )
        {
            this->setLevel(this->getLevel() + 1);
        }
        
        enemy->setLife(this->getLevel() + 3);
        
        this->m_createDelay = 1.0f;
    }
}
/**
 * カウントの初期化
 */
void EnemyGenerator::reset()
{
    this->m_createDelay = 0.0f;
    this->setMakeCount(0);
    this->setLevel(0);
}

