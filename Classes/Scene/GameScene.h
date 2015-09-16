//
//  GameScene.h
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/16.
//
//

#ifndef __care_of_road__GameScene__
#define __care_of_road__GameScene__

#include "cocos2d.h"
#include "RollBackgroundLayer.h"

#include "BulletObject.h"
#include "EnemyObject.h"

class GameScene : public cocos2d::Layer
{
protected:
    RollBackgroundLayer * m_roll;
    
    cocos2d::Vector<EnemyObject*> m_EnemyList;
    cocos2d::Vector<BulletObject*> m_BulletList;
    
    cocos2d::Layer* m_EnemyLayer;
    cocos2d::Layer* m_BulletLayer;
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(GameScene);

    /**
     * 更新
     */
    virtual void update(float dt);
    
    /**
     * 敵オブジェクトの追加
     */
    virtual void entryEnemyObject(cocos2d::Vec2 position, EnemyObject* obj);

    /**
     * 弾オブジェクトの追加
     */
    virtual void entryBulletObject(cocos2d::Vec2 position, BulletObject* obj);
};

#endif /* defined(__care_of_road__GameScene__) */
