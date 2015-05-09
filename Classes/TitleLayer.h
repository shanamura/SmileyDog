//
//  TitleLayer.h
//  SmileyDog
//
//  Created by hashi on 2015/05/10.
//
//

#ifndef __SmileyDog__TitleLayer__
#define __SmileyDog__TitleLayer__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"

class TitleLayer : public cocos2d::Layer
{
protected:
    void createTitle();
    
    void createButton();
    void onTapButton(cocos2d::Ref* sender, cocos2d::extension::Control::EventType controlEvent);
    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    virtual void onEnter();
    CREATE_FUNC(TitleLayer);
};

#endif // __SmileyDog__TitleLayer__