#pragma once
#include "FollowMouse.h"
#include "raymath.h"

FollowMouse::FollowMouse() {

}

FollowMouse::~FollowMouse() {

}

void FollowMouse::Update(Ball* ball, float deltaTime) {
	Vector2 mousePosition = GetMousePosition();
	Vector2 direction = Vector2Subtract(mousePosition, ball->GetPosition());
	ball->acceleration = Vector2Scale(Vector2Normalize(direction), (ball->GetAccFactor() * deltaTime));
}