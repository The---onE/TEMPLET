#pragma once

#include "Global.h"
#include "Data/BackgroundData.h"

class BackgroundLayer : public Layer
{
protected:
	Sprite* bG; //±³¾°Í¼Æ¬
	Sprite* tempBg; //ÇÐ»»±³¾°

	float bgWidth; //Í¼Æ¬¿í¶È

public:
	CREATE_FUNC(BackgroundLayer);
	bool init();

	void move(float delta);
};