#include "StateList.h"

bool StartState::checkStateChange() //״̬�ı䷵��true��״̬δ�ı䷵��false��
{
	//if (time > 1000)
		//CHANGE_TO_STATE(InitiationState);
	return false;
}

bool StartState::entryState()
{
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