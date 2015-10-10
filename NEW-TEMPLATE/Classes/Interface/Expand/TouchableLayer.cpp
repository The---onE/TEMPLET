#include "TouchableLayer.h"

//接收触控信息，子类不要覆盖
void TouchableLayer::onEnter()
{
	do
	{
		Layer::onEnter();

		auto listener = EventListenerTouchOneByOne::create();
		listener->setSwallowTouches(false);
		listener->onTouchBegan = CC_CALLBACK_2(TouchableLayer::onTouchBegan, this);
		listener->onTouchMoved = CC_CALLBACK_2(TouchableLayer::onTouchMoved, this);
		listener->onTouchEnded = CC_CALLBACK_2(TouchableLayer::onTouchEnded, this);
		listener->onTouchCancelled = CC_CALLBACK_2(TouchableLayer::onTouchEnded, this);

		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	} while (0);
}

//允许触控
void TouchableLayer::allowResponse()
{
	responseFlag = true;
}

//不允许触控
void TouchableLayer::forbiddenResponse()
{
	responseFlag = false;
}

//是否允许触控
bool TouchableLayer::isResponse()
{
	return responseFlag;
}