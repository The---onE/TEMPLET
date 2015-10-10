#include "GameScene.h"

bool GameScene::init()
{
	Scene::init();

	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(GameScene::quitGame, this));
	closeItem->setPosition(Point(visibleSize.width / 2, 0));
	closeItem->setAnchorPoint(Point(0.5f, 0));
	SETSIZE(closeItem, 0.05);
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);

	stateMachine = StateMachine::createWithGameScene(this);
	stateMachine->changeState(StartState::create(this));

	this->scheduleUpdate();

	return true;
}

StateMachine* GameScene::getStateMachine()
{
	return stateMachine;
}

void GameScene::update(float dt)
{
	stateMachine->update(dt);
}


void GameScene::quitGame(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
