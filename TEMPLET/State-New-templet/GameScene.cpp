#include "GameScene.h"
#include "State/StateList.h"

bool GameScene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Scene::init());

		createQuitButton("QuitNormal.png", "QuitSelected.png");
		
		stateMachine = StateMachine::createWithGameScene(this);
		stateMachine->changeState(StartState::create(this));

		this->scheduleUpdate();

		//auto rootNode = CSLoader::createNode("MainScene.csb");
		//addChild(rootNode);

		bRet = true;
	} while (0);
	return bRet;
}

StateMachine* GameScene::getStateMachine()
{
	return stateMachine;
}

void GameScene::update(float dt)
{
	stateMachine->update(dt);
}

void GameScene::createQuitButton(string normal, string selected)
{
	auto closeItem = MenuItemImage::create(normal, selected, CC_CALLBACK_1(GameScene::quitGame, this));
	closeItem->setPosition(Point(visibleSize.width / 2, 0));
	closeItem->setAnchorPoint(Point(0.5f, 0));
	SETSIZE(closeItem, 0.08);
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);
}

void GameScene::quitGame(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
