
#pragma once

#include "Global.h"
#include "State/StateMachine/StateMachine.h"
#include "Interface/Interface.h"
#include "User/User.h"

class GameScene : public Scene
{
protected:
	BackgroundLayer* background; //背景层
	InformationLayer* information; //信息层

	Players* players; //玩家信息

	void restart(Ref* pSender); //开始新游戏

	void createQuitButton(string normal, string selected); //创建退出游戏按钮
	void quitGame(Ref* pSender); //退出游戏

public:
	CREATE_FUNC(GameScene);
	bool init();

	void initGame(); //初始化一局游戏

	void initBackground(); //初始化背景层
	void initInformation(); //初始化信息层

	void initPlayers(); //初始化玩家
	void initMaster(); //初始化主控玩家

	void moveBackground(float delta); //背景移动

	void gameOver(); //游戏结束，显示分数，提示开始新游戏

public:
	StateMachine* stateMachine; //状态机
	StateMachine* getStateMachine(); //返回状态机指针
	void update(float dt);
};

