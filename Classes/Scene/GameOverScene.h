//
//  GameOverScene.hpp
//  care_of_road
//
//  Created by 大原幸夫 on 2015/09/22.
//
//

#ifndef GameOverScene_hpp
#define GameOverScene_hpp

#include "cocos2d.h"
#include "RollBackgroundLayer.h"


class GameOverScene : public cocos2d::Layer
{
protected:
    RollBackgroundLayer * m_roll;
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(GameOverScene);
    
    /**
     * ゲーム画面に移動
     */
    void moveToGame(cocos2d::Ref * sender);
    /**
     * パワーアップ画面に移動
     */
    void moveToPowrUp(cocos2d::Ref * sender);
    /**
     * ランキング画面に移動
     */
    void moveToRanking(cocos2d::Ref * sender);
    /**
     * タイトル画面に移動
     */
    void moveToTitle(cocos2d::Ref * sender);
};

#endif /* GameOverScene_hpp */
