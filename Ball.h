#pragma once
#include "raylib.h"
#include "Trailing.h"
#include <memory>
#include <vector>
#include "raymath.h"

class IBehaviour;
class Trailing;

class Ball {
public:
	Vector2 acceleration = {0.0f, 0.0f};
	Vector2 velocity = { 0.0f, 0.0f };

	Ball();
	Ball(Vector2 pos, float radius, Color colour);
	Ball(Vector2 pos, float radius, Color colour, bool doTrail);

	virtual ~Ball() {};

	virtual void Update(float deltaTime);
	virtual void Draw();

	void SetPosition(Vector2 pos);
	Vector2 GetPosition();
	float GetMaxSpeed();
	float GetAccFactor();
	Color GetColor();

	int AddBehaviour(IBehaviour* behaviour);
	void RemoveBehaviour(int index);

	// Trailing options
	void EnableTrail();
	void DisableTrail();
	void ToggleTrail();

	void SetTrailLength(int length);
	int GetTrailLength();
	Trailing* GetTrailing();


private:
	float _maxSpeed{ 300.0f };
	float _accFactor{ 250.0f };
	std::vector<IBehaviour*> _behaviours;

	Vector2 _position{ 0.0f, 0.0f };
	float _radius{ 5.0f };
	Color _color{ BLUE };

	std::unique_ptr<Trailing> _trailing;
	int _trailLength = 30;
	int _trailIndex = 0;
};