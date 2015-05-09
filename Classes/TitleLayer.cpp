//
//  TitleLayer.cpp
//  SmileyDog
//
//  Created by hashi on 2015/05/10.
//
//

#include "TitleLayer.h"
#include "GameLayer.h"
#include "SimpleAudioEngine.h"

#define WINSIZE Director::getInstance()->getWinSize()

#define REMAINING 3

USING_NS_CC;
USING_NS_CC_EXT;
using namespace CocosDenshion;

Scene* TitleLayer::createScene()
{
    auto scene = Scene::create();
    auto layer = TitleLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}

//タイトル画面の初期化
bool TitleLayer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto audio = SimpleAudioEngine::getInstance();
    
    //BGMの再生
    if(!audio->isBackgroundMusicPlaying())
    {
        audio->playBackgroundMusic("bgm.mp3", true);
    }
    
    return true;
}

void TitleLayer::onEnter()
{
    Layer::onEnter();
    
    createTitle();
    createButton();
}

//タイトル背景画像の作成
void TitleLayer::createTitle()
{
    auto background = Sprite::create("background.png");
    background->setAnchorPoint(Point(0, 0.5));
    background->setPosition(Point(0, WINSIZE.height /2));
    
    addChild(background);
}

//スタートボタンの作成
void TitleLayer::createButton()
{
    auto button = ControlButton::create(Scale9Sprite::create("getready.png"));
    button->setAdjustBackgroundImage(false);
    
    button->setPosition(Point(WINSIZE / 2));
    
    button->addTargetWithActionForControlEvents(this, cccontrol_selector(TitleLayer::onTapButton), Control::EventType::TOUCH_UP_INSIDE);
    
    addChild(button);
}

//ボタン処理
void TitleLayer::onTapButton(Ref* sender, Control::EventType controlEvent)
{
    auto scene = GameLayer::createScene(REMAINING, 1);
    
    auto tran = TransitionFade::create(2.0, scene);
    Director::getInstance()->replaceScene(tran);
}

