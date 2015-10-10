#include "GameScene.h"
#include "State/StateList.h"

bool GameScene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Scene::init());

		//auto rootNode = CSLoader::createNode("MainScene.csb");
		//addChild(rootNode);

		createQuitButton("images/QuitNormal.png", "images/QuitSelected.png"); //添加退出游戏按钮
		stateMachine = StateMachine::createWithGameScene(this); //创建状态机
		stateMachine->changeState(StartState::create(this)); //进入准备开始游戏状态
		this->scheduleUpdate();

		bRet = true;
	} while (0);
	return bRet;
}

//初始化一局游戏
void GameScene::initGame()
{

}

//初始化背景层
void GameScene::initBackground()
{
	background = BackgroundLayer::create();
	addChild(background);
}

//初始化矩阵层
void GameScene::initInformation()
{
	information = InformationLayer::create();
	addChild(information);
}

//初始化玩家
void GameScene::initPlayers()
{
	players = Players::create();
	addChild(players);
}

//初始化主控玩家
void GameScene::initMaster()
{
	players->createAlly(MASTER_ID);
	players->setMaster(MASTER_ID);
}

void GameScene::gameOver()
{
// 	int score = players->getScore();
// 	int high = UserDefault::getInstance()->getIntegerForKey(HIGH_SCORE_UD, 0);
// 	Label* label;
// 	if (score > high)
// 	{
// 		char text[128];
// 		sprintf(text, "New Record!\nScore:%d\nHigh Score:%d\nPress To Start A New Game.", score, score);
// 
// 		UserDefault::getInstance()->setIntegerForKey(HIGH_SCORE_UD, score);
// 
// 		//若开启音效，则播放胜利音效
// 		//if (UserDefault::getInstance()->getBoolForKey(EFFECT_STR, EFFECT_DEFAULT_FLAG))
// 		//	SimpleAudioEngine::getInstance()->playEffect(WIN_EFFECT);
// 
// 		label = Label::createWithTTF(text, INFORMATION_FONT, GAME_OVER_SIZE, Size::ZERO, TextHAlignment::CENTER); //创建Label
// 		label->setTextColor(GAME_OVER_COLOR);
// 		label->enableShadow(Color4B::BLACK, Size(5, -5)); //添加阴影
// 	}
// 	else
// 	{
// 		char text[128];
// 		sprintf(text, "Score:%d\nHigh Score:%d\nPress To Start A New Game.", score, high);
// 
// 		//若开启音效，则播放胜利音效
// 		//if (UserDefault::getInstance()->getBoolForKey(EFFECT_STR, EFFECT_DEFAULT_FLAG))
// 		//	SimpleAudioEngine::getInstance()->playEffect(WIN_EFFECT);
// 
// 		label = Label::createWithTTF(text, INFORMATION_FONT, GAME_OVER_SIZE, Size::ZERO, TextHAlignment::CENTER); //创建Label
// 		label->setTextColor(GAME_OVER_COLOR);
// 		label->enableShadow(Color4B::BLACK, Size(5, -5)); //添加阴影
// 	}
// 
// 	MenuItemLabel* re = MenuItemLabel::create(label, CC_CALLBACK_1(GameScene::restart, this)); //创建菜单项，按下时调用开始新游戏函数
// 	Menu* menu = Menu::create(re, NULL);
// 	addChild(menu, 1000);
}


//开始新游戏
void GameScene::restart(Ref* pSender)
{
	Scene* s = GameScene::create();
	Director::getInstance()->replaceScene(s); //用新的Game场景替换原场景，开始新游戏
}

//创建退出游戏按钮
void GameScene::createQuitButton(string normal, string selected)
{
	auto closeItem = MenuItemImage::create(normal, selected, CC_CALLBACK_1(GameScene::quitGame, this));
	closeItem->setPosition(Point(WIDTH / 2, 0));
	closeItem->setAnchorPoint(Point(0.5f, 0));
	setSize(closeItem, 0.08f);
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
}
//退出游戏
void GameScene::quitGame(Ref* pSender)
{
	Director::getInstance()->popScene(); //返回上一场景
}

//返回状态机指针
StateMachine* GameScene::getStateMachine()
{
	return stateMachine;
}
//游戏主循环
void GameScene::update(float dt)
{
	stateMachine->update(dt); //游戏主循环由状态机调度
}