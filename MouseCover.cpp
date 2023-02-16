#pragma once
#include "raylib.h"
#include "MouseCover.h"

MouseCover::MouseCover(Color color) {
	_color = color;
}
MouseCover::~MouseCover() {}

void MouseCover::Update() {
	_position = GetMousePosition();
}

void MouseCover::Draw() {
	DrawRectangle((int)_position.x - _width/2, (int)_position.y - _height / 2, _width, _height, _color);
}
