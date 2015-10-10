#pragma once

#include "Global.h"
#include "StateMachine.h"

class GameScene : public Scene
{
protected:
	StateMachine* stateMachine; //状态机

public:
	CREATE_FUNC(GameScene);
	bool init();
	StateMachine* getStateMachine(); //返回状态机指针
	void update(float dt);

	void createQuitButton(string normal, string selected);
	void quitGame(Ref* pSender); //退出游戏
};

