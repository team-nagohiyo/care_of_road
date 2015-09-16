//
//  BulletObject.h
//  care_of_road
//
//  Created by ooharayukio on 2015/09/16.
//
//

#ifndef __care_of_road__BulletObject__
#define __care_of_road__BulletObject__

#include "cocos2d.h"
#include "HitObject.h"

/**
 * 敵のオブジェクト
 */
class BulletObject : public HitObject
{
    CC_SYNTHESIZE(int, m_Id, Id);
    CC_SYNTHESIZE(int, m_Type, Type);
    CC_SYNTHESIZE(int, m_Score, Score);
    CC_SYNTHESIZE(int, m_Attack, Attack);
protected:
    cocos2d::Sprite * m_mainSprite;
public:
    BulletObject();
    virtual ~BulletObject();
    static BulletObject* create(int charaId);
    bool init(int charaId);
};

#endif /* defined(__care_of_road__BulletObject__) */
