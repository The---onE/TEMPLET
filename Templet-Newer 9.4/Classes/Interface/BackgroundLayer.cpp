#include "BackgroundLayer.h"

bool BackgroundLayer::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Layer::init());

		addSprite(bG, BACKGROUND_IMG, Point::ZERO, BACKGROUND_SIZE, this, Point::ZERO); //½«±³¾°Í¼Æ¬Ìí¼Óµ½ÆÁÄ»
		addSprite(tempBg, BACKGROUND_IMG, Point(WIDTH, 0), BACKGROUND_SIZE, this, Point(1, 0));

		tempBg->setVisible(false);

		bgWidth = bG->getContentSize().width * bG->getScaleY();

		bRet = true;
	} while (0);
	return bRet;
}

void BackgroundLayer::move(float delta)
{
	float x = bG->getPositionX() - delta;
	float y = bG->getPositionY();
	if (x < WIDTH - bgWidth)
	{
		x = WIDTH;
		tempBg->setVisible(true);
		tempBg->setPosition(Point(x, 0));
	}
	bG->setPosition(Point(x, y));
	if (tempBg->isVisible())
	{
		if (x < 0)
		{
			tempBg->setVisible(false);
		}
		tempBg->setPosition(Point(x, y));
	}
}