#pragma once

#include "Global.h"
#include "Data/BackgroundData.h"

class BackgroundLayer : public Layer
{
protected:
	Sprite* bG; //����ͼƬ
	Sprite* tempBg; //�л�����

	float bgWidth; //ͼƬ���

public:
	CREATE_FUNC(BackgroundLayer);
	bool init();

	void move(float delta);
};