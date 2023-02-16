#pragma once
#include "raylib.h"

class MouseCover {
public:
	Color _color{ RAYWHITE };

	MouseCover(Color color);
	~MouseCover();

	void Update();
	void Draw();
private:
	int _width = 10;
	int _height = 10;
	Vector2 _position = {0.0f, 0.0f};
};

