#pragma once

#include "Global.h"

class MainScene : public Scene
{
public:
	CREATE_FUNC(MainScene);
    virtual bool init();
	void quitGame(Ref* pSender);
};
