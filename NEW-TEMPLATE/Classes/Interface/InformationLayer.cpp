#include "InformationLayer.h"

bool InformationLayer::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());

		bRet = true;
	} while (0);
	return bRet;
}

//添加一个标签
void InformationLayer::createLabel(Label* &label, char* text, Color4B color, Point pos, float size, Point anchor /* = Point(0.5, 0.5) */)
{
	label = Label::createWithTTF(text, INFORMATION_FONT, INFORMATION_FONTSIZE);
	label->setTextColor(color);
	label->enableShadow(Color4B::BLACK, INFORMATION_SHADOW_OFFSET);
	label->setPosition(pos);
	label->setAnchorPoint(anchor);
	setSize(label, size);
	addChild(label);
}
