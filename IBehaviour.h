#pragma once
#include <raylib.h>

class Ball;
class IBehaviour {
public:
	IBehaviour() {}
	~IBehaviour() {}

	// Función virtual pura = 0
	virtual void Update(Ball* agent, float deltaTime) = 0;
};