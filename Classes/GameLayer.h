//
//  GameLayer.h
//  SmileyDog
//
//  Created by hashi on 2015/05/07.
//
//

#ifndef __SmileyDog__GameLayer__
#define __SmileyDog__GameLayer__

#include "cocos2d.h"

class GameLayer : public cocos2d::Layer
{
    
    
protected:
    enum Tag
    {
        T_BackGround = 1,
        T_Enemy,
        
        T_Ball,
        T_Gum1,
        T_Gum2,
        T_Block,
    };
    
    enum ZOrder
    {
        Z_BackGround = 1,
        Z_Enemy,
        
        Z_Launcher2,
        Z_Gum2,
        Z_Ball,
        Z_Gum1,
        Z_Launcher1,
        Z_Block,
        
        Z_Fog,
        Z_Star,
        
        Z_Result,
    };
    
    enum BlockType
    {
        Block1,
        Block2,
        Roof,
        Stone,
    };
    
    //残機
    int _remaining;
    //ステージ
    int _level;
    
    void createBackground();
    void createGround();
    
    void createEnemy(cocos2d::Point position);
    
    void createBall();
    cocos2d::Point calculatedPosition(cocos2d::Point touchPosition);
    
    void applyingForceToBall(cocos2d::Node* ball);
    
    //敵とブロックの生成
    void createBlockAndEnemy(int level);
    //ブロックの生成
    void createBlock(BlockType type, cocos2d::Point position, float angle);
    
    void contactedBall();
    void removingEnemy(cocos2d::Node* enemy);
    
    void successGame();
    void failureGame(float dt);
    
    
public:
    static cocos2d::Scene* createScene(int remaining, int level);
    virtual bool init(int remaining, int level);
    
    //引数を持たせるのでCREATE_FUNC(GameLayer)の代わりに以下へ変更
    static GameLayer* create(int remaining, int level);
    
    virtual void onEnter();
    virtual void update(float dt);
    
    virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* unused_event);
    
    bool onContactBegin(cocos2d::PhysicsContact& contact);
};

#endif /* defined(__SmileyDog__GameLayer__) */
