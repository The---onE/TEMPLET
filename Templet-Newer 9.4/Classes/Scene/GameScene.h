
#pragma once

#include "Global.h"
#include "State/StateMachine/StateMachine.h"
#include "Interface/Interface.h"
#include "User/User.h"

class GameScene : public Scene
{
protected:
	BackgroundLayer* background; //������
	InformationLayer* information; //��Ϣ��

	Players* players; //�����Ϣ

	void restart(Ref* pSender); //��ʼ����Ϸ

	void createQuitButton(string normal, string selected); //�����˳���Ϸ��ť
	void quitGame(Ref* pSender); //�˳���Ϸ

public:
	CREATE_FUNC(GameScene);
	bool init();

	void initGame(); //��ʼ��һ����Ϸ

	void initBackground(); //��ʼ��������
	void initInformation(); //��ʼ����Ϣ��

	void initPlayers(); //��ʼ�����
	void initMaster(); //��ʼ���������

	void moveBackground(float delta); //�����ƶ�

	void gameOver(); //��Ϸ��������ʾ��������ʾ��ʼ����Ϸ

public:
	StateMachine* stateMachine; //״̬��
	StateMachine* getStateMachine(); //����״̬��ָ��
	void update(float dt);
};

