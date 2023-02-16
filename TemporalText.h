#pragma once
#include "IGUIElement.h"
#include "raylib.h"
#include <string>

class TemporalText : public IGUIElement {
public:
	TemporalText(const char* label, Vector2 position);
	TemporalText(const char* label, int fontSize, Vector2 position);
	TemporalText(const char* label, int fontSize, Vector2 position, float screenTime);
	~TemporalText();

	void Draw();
	void Update(float deltaTime);

	void SetLabel(std::string label);
	void Show();
	void Hide();
	std::string GetLabel();
	void SetScreenTime(int time);

private:
	std::string _label;
	Vector2 _position = { 0, 0 };
	int _opacity = 255;
	float _screenTime = 1; // in seconds
	Font _fontTtf;
};

