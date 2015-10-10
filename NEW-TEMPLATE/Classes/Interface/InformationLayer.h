#pragma once

#include "Global.h"
#include "Data/InformationData.h"

class InformationLayer : public Layer
{
protected:
	Label* timeLabel;
	Label* scoreLabel;

public:
	CREATE_FUNC(InformationLayer);
	bool init();

	void createLabel(Label* &label, char* text, Color4B color, Point pos, float size, Point anchor = Point(0.5, 0.5)); //添加一个标签
};
