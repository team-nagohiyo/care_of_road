//
//  TitleScene.h
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/14.
//
//

#ifndef __care_of_road__TitleScene__
#define __care_of_road__TitleScene__

#include "cocos2d.h"


class TitleScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(TitleScene);
};


#endif /* defined(__care_of_road__TitleScene__) */
