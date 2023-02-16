#pragma once
#include "raylib.h"
#include "Ball.h"
#include <memory>

Ball::Ball() {
}

Ball::Ball(Vector2 pos, float radius, Color color) :
	_position{ pos }, _radius{ radius }, _color{ color }
{

}

Ball::Ball(Vector2 pos, float radius, Color color, bool doTrail) :
	_position{ pos }, _radius{ radius }, _color{ color } 
{
	if (doTrail) {
		EnableTrail();
	}
}

void Ball::SetPosition(Vector2 pos) {
	_position = pos;
}

Vector2 Ball::GetPosition() {
	return _position;
}

float Ball::GetMaxSpeed() {
	return _maxSpeed;
}

float Ball::GetAccFactor() {
	return _accFactor;
}

Color Ball::GetColor() {
	return _color;
}

Trailing* Ball::GetTrailing() {
	return _trailing.get();
}

void Ball::SetTrailLength(int length) {
	if (length > 0) {
		_trailLength = length;
	}
}

int Ball::GetTrailLength() {
	return _trailLength;
}

void Ball::EnableTrail() {
	if (!_trailing) {
		_trailing = std::make_unique<Trailing>(_trailLength);
		_trailIndex = AddBehaviour(_trailing.get());
	}
}

void Ball::DisableTrail() {
	if (_trailing) {
		RemoveBehaviour(_trailIndex);
		_trailing.reset(); // Deletes object and makes ptr null.
	}
}

void Ball::ToggleTrail() {
	if (_trailing) {
		DisableTrail();
	}
	else {
		EnableTrail();
	}
}

void Ball::Update(float deltaTime) {
	for (int i = 0; i < _behaviours.size(); i++) {
		_behaviours[i]->Update(this, deltaTime);
	}

	velocity.x += acceleration.x;
	velocity.y += acceleration.y;

	if (Vector2Length(velocity) > _maxSpeed) {
		velocity = Vector2Scale(Vector2Normalize(velocity), _maxSpeed);
	}

	_position.x += velocity.x * deltaTime;
	_position.y += velocity.y * deltaTime;
}

void Ball::Draw() {
	DrawCircle((int)_position.x, (int)_position.y, _radius, _color);
	if (_trailing) {
		_trailing->Draw(_color);
	}
}

int Ball::AddBehaviour(IBehaviour* behaviour) {
	_behaviours.push_back(behaviour);
	return _behaviours.size() - 1;
}

void Ball::RemoveBehaviour(int index) {
	_behaviours.erase(_behaviours.begin() + index);
}