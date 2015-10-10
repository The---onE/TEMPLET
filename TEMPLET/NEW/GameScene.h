#pragma once

#include "Global.h"
#include "StateMachine.h"

class GameScene : public Scene
{
protected:
	StateMachine* stateMachine; //״̬��

public:
	CREATE_FUNC(GameScene);
	bool init();
	StateMachine* getStateMachine(); //����״̬��ָ��
	void update(float dt);

	void createQuitButton(string normal, string selected);
	void quitGame(Ref* pSender); //�˳���Ϸ
};

