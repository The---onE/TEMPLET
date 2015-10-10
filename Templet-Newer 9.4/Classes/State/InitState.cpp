#include "StateList.h"

bool InitState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	//if (time > 0)
	//	CHANGE_TO_STATE(InitState);
	return false;
}

bool InitState::entryState()
{

	return true;
}

void InitState::onUpdate(float dt)
{
	time += dt;
	scene->moveBackground(200);
}

bool InitState::exitState()
{
	return true;
}