#pragma once

#include "Global.h"

class TouchableLayer : public Layer //可触控层拓展
{
protected:
	bool responseFlag; //是否响应触控

public:
	void onEnter(); //接收触控信息，子类不要覆盖

	void allowResponse(); //允许触控
	void forbiddenResponse(); //不允许触控

	bool isResponse(); //是否允许触控

	bool onTouchBegan(Touch *touch, Event *unused_event) = 0; //开始触控接口
 	void onTouchMoved(Touch *touch, Event *unused_event) = 0; //触点移动接口
	void onTouchEnded(Touch *touch, Event *unused_event) = 0; //触控结束接口
};