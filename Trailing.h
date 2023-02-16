#pragma once
#include "IBehaviour.h"
#include "Ball.h"
#include <vector>

struct TrailPoint {
	Vector2 position;
	float size;
};

class Trailing : public IBehaviour {
public:
	Trailing(int trailLength);
	~Trailing();

	virtual void Update(Ball* Ball, float deltaTime);

	void Draw(Color color);

private:
	int _counter = 0;
	int _frameCounter = 0;
	float _frequency = 0.2f;
	float _size = 5.0f;
	int _length = 30;
	unsigned char _opacity = 220;
	std::vector<TrailPoint> _lastPoints;

	void Count();
};

