#include "StateList.h"

bool InitState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
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