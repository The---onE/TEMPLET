#pragma once
#include "Global.h"

#include "GameScene.h"

#define CREATE_STATE(__TYPE__) \
static __TYPE__* create(GameScene* scene) \
{ \
    __TYPE__ *pRet = new __TYPE__(); \
    if (pRet && pRet->entryState(scene)) \
	{ \
        pRet->autorelease(); \
        CC_SAFE_RETAIN(pRet);
        return pRet; \
	} \
	else \
	{ \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
	} \
}

#define DEFINE_STATE(STATE) class STATE : public State \
{ \
public: \
	CREATE_STATE(STATE); \
	bool checkStateChange(GameScene* scene); \
	bool entryState(GameScene* scene); \
	void onUpdate(GameScene* scene); \
	bool exitState(GameScene* scene); \

#define END_DEFINE_STATE };

#define CHANGE_TO_STATE(STATE) exitState(scene); scene->getStateMachine()->changeState(STATE::create(scene));

class GameScene;

class State : public Node
{
public: 
	virtual bool checkStateChange(GameScene* scene) = 0; //状态改变返回true，状态未改变返回false，
	virtual bool entryState(GameScene* scene) = 0;
	virtual void onUpdate(GameScene* scene) = 0;
	virtual bool exitState(GameScene* scene) = 0;
};

DEFINE_STATE(StartState)
END_DEFINE_STATE