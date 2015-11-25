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
#include "PlayerObject.h"
#include "TouchControlLayer.h"

class GameScene : public cocos2d::Layer
{
public:
    //ゲームの進行ステート
    enum struct GameState:int
    {
        StartWait = 0,
        Starting,
        GamePlay,
        GameOverWait,
        GameOver,
    };

    CC_SYNTHESIZE(GameState, m_State, State);
protected:
    RollBackgroundLayer * m_roll;
    
    cocos2d::Vector<EnemyObject*> m_EnemyList;
    cocos2d::Vector<BulletObject*> m_BulletList;
    
    cocos2d::Layer* m_EnemyLayer;
    cocos2d::Layer* m_BulletLayer;
    TouchControlLayer * m_TouchControl;
    
    PlayerObject * m_PlayerObject;
    
    cocos2d::Rect m_TouchRect;
    
    cocos2d::Label * m_ScoreLabel;
    
    //プレイヤーの初期ポジション
    cocos2d::Vec2 m_StartingPos;
    cocos2d::Vec2 m_StartPos;
    
    cocos2d::Sprite * m_TapStartSprite;
    
    //ゲームオーバー待ち時間
    float m_GameOverWaitTime;
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    
    CREATE_FUNC(GameScene);
    
    GameScene();
    virtual ~GameScene();
    /**
     * 更新
     */
    virtual void update(float dt);
    
    /**
     * ヒットチェック
     */
    virtual void hitCheck();
    
    /**
     * 行動
     */
    virtual void updateAction(float dt);
    
    /**
     * 魂状態の人を削除
     */
    virtual void removeObjectWithSoul();
    
    /**
     * 敵オブジェクトの追加
     */
    virtual void entryEnemyObject(EnemyObject* obj);

    /**
     * 弾オブジェクトの追加
     */
    virtual void entryBulletObject(BulletObject* obj);
    

    /**
     * スコア表示の更新
     */
    virtual void refreshScoreLabel();
    
    /**
     * 共通操作処理
     */
    virtual void sharedTapControl(cocos2d::Vec2 pos,TouchControlLayer::TapType type);
    /**
     * コントローラのタップ開始
     */
    virtual void OnControlTapBegan(cocos2d::Vec2 pos,TouchControlLayer::TapType type);
    /**
     * コントローラのタップ移動
     */
    virtual void OnControlTapMoved(cocos2d::Vec2 pos,TouchControlLayer::TapType type);
    /**
     * コントローラのタップ終了
     */
    virtual void OnControlTapEnded(cocos2d::Vec2 pos,TouchControlLayer::TapType type);
    
    /**
     * ゲームオーバー画面に移動
     */
    void moveToGameOver();
};

#endif /* defined(__care_of_road__GameScene__) */
