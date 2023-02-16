#pragma once
#include "IBehaviour.h"
#include "Ball.h"

class FollowMouse : public IBehaviour {
public:
	FollowMouse();
	~FollowMouse();

	virtual void Update(Ball* ball, float deltaTime);
};