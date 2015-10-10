#pragma once
#include "Global.h"

#include "StateMachine.h"
#include "State.h"

class GameScene : public Scene
{
public:
	StateMachine* stateMachine;

	CREATE_FUNC(GameScene);
	bool init();
	StateMachine* getStateMachine();
	void update(float dt);
	void quitGame(Ref* pSender);
};
