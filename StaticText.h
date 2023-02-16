#pragma once
#include "IGUIElement.h"
#include "raylib.h"
#include <string>

class StaticText :
    public IGUIElement
{
public:
	StaticText(const char* label, Vector2 position);
	StaticText(const char* label, int fontSize, Vector2 position);
	~StaticText();

	void Draw();
	void Update(float deltaTime);

	void SetLabel(std::string label);
	void Show();
	void Hide();
	std::string GetLabel();
	void SetScreenTime(int time);
	int Opacity = 255;

private:
	std::string _label;
	Vector2 _position = { 0, 0 };
	Font _fontTtf;
};
