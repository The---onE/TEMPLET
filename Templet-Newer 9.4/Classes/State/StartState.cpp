#include "StateList.h"

bool StartState::checkStateChange() //状态改变返回true，状态未改变返回false，
{
	if (time > 0)
		CHANGE_TO_STATE(InitState);
	return false;
}

bool StartState::entryState()
{
	scene->initBackground();
	scene->initInformation();

	return true;
}

void StartState::onUpdate(float dt)
{
	time += dt;
}

bool StartState::exitState()
{
	return true;
}