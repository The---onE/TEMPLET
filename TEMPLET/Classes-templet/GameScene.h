#pragma once

#include "Global.h"

class GameScene : public Scene
{
public:
	CREATE_FUNC(GameScene);
	bool init();
	void update(float dt);
	void quitGame(Ref* pSender);
};
