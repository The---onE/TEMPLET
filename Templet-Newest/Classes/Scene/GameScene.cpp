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

		createQuitButton("images/QuitNormal.png", "images/QuitSelected.png"); //����˳���Ϸ��ť
		stateMachine = StateMachine::createWithGameScene(this); //����״̬��
		stateMachine->changeState(StartState::create(this)); //����׼����ʼ��Ϸ״̬
		this->scheduleUpdate();

		bRet = true;
	} while (0);
	return bRet;
}

//��ʼ��һ����Ϸ
void GameScene::initGame()
{

}

//��ʼ��������
void GameScene::initBackground()
{
	background = BackgroundLayer::create();
	addChild(background);
}

//��ʼ�������
void GameScene::initInformation()
{
	information = InformationLayer::create();
	addChild(information);
}

//��ʼ�����
void GameScene::initPlayers()
{
	players = Players::create();
	addChild(players);
}

//��ʼ���������
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
// 		//��������Ч���򲥷�ʤ����Ч
// 		//if (UserDefault::getInstance()->getBoolForKey(EFFECT_STR, EFFECT_DEFAULT_FLAG))
// 		//	SimpleAudioEngine::getInstance()->playEffect(WIN_EFFECT);
// 
// 		label = Label::createWithTTF(text, INFORMATION_FONT, GAME_OVER_SIZE, Size::ZERO, TextHAlignment::CENTER); //����Label
// 		label->setTextColor(GAME_OVER_COLOR);
// 		label->enableShadow(Color4B::BLACK, Size(5, -5)); //�����Ӱ
// 	}
// 	else
// 	{
// 		char text[128];
// 		sprintf(text, "Score:%d\nHigh Score:%d\nPress To Start A New Game.", score, high);
// 
// 		//��������Ч���򲥷�ʤ����Ч
// 		//if (UserDefault::getInstance()->getBoolForKey(EFFECT_STR, EFFECT_DEFAULT_FLAG))
// 		//	SimpleAudioEngine::getInstance()->playEffect(WIN_EFFECT);
// 
// 		label = Label::createWithTTF(text, INFORMATION_FONT, GAME_OVER_SIZE, Size::ZERO, TextHAlignment::CENTER); //����Label
// 		label->setTextColor(GAME_OVER_COLOR);
// 		label->enableShadow(Color4B::BLACK, Size(5, -5)); //�����Ӱ
// 	}
// 
// 	MenuItemLabel* re = MenuItemLabel::create(label, CC_CALLBACK_1(GameScene::restart, this)); //�����˵������ʱ���ÿ�ʼ����Ϸ����
// 	Menu* menu = Menu::create(re, NULL);
// 	addChild(menu, 1000);
}


//��ʼ����Ϸ
void GameScene::restart(Ref* pSender)
{
	Scene* s = GameScene::create();
	Director::getInstance()->replaceScene(s); //���µ�Game�����滻ԭ��������ʼ����Ϸ
}

//�����˳���Ϸ��ť
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
//�˳���Ϸ
void GameScene::quitGame(Ref* pSender)
{
	Director::getInstance()->popScene(); //������һ����
}

//����״̬��ָ��
StateMachine* GameScene::getStateMachine()
{
	return stateMachine;
}
//��Ϸ��ѭ��
void GameScene::update(float dt)
{
	stateMachine->update(dt); //��Ϸ��ѭ����״̬������
}