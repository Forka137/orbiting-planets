#pragma once
#include "TemporalText.h"
#include "raylib.h"
#include <iostream>
#include <string>

TemporalText::TemporalText(const char* label, Vector2 position) {
	_label = label;
	_position = position;
	_screenTime = 1.0;
	_fontTtf = LoadFontEx("resources/anonymous_pro_bold.ttf", 11, 0, 256);
}


TemporalText::TemporalText(const char* label, int fontSize, Vector2 position) {
	_label = label;
	_position = position;
	_screenTime = 1.0;
	_fontTtf = LoadFontEx("resources/anonymous_pro_bold.ttf", fontSize, 0, 256);
}

TemporalText::TemporalText(const char* label, int fontSize, Vector2 position, float screenTime) {
	_label = label;
	_position = position;
	_screenTime = screenTime;
	_fontTtf = LoadFontEx("resources/anonymous_pro_bold.ttf", fontSize, 0, 256);
}

TemporalText::~TemporalText() {

}

void TemporalText::SetLabel(std::string label) {
	Show();
	_label = label;
}

std::string TemporalText::GetLabel() {
	return _label;
}

void TemporalText::SetScreenTime(int time) {
	_screenTime = time;
}

void TemporalText::Show() {
	_opacity = 255;
}

void TemporalText::Hide() {
	_opacity = 0;
}

void TemporalText::Draw() {
	// std::cout << "Dibujando texto" << std::endl;
	if (_opacity > 0) {
		DrawTextEx(_fontTtf, _label.c_str(), _position, (float)_fontTtf.baseSize, 2, { 220, 220, 220, (unsigned char)_opacity});
	}
}

void TemporalText::Update(float deltaTime) {
	if (_opacity > 0) {
		_opacity = _opacity - ((deltaTime * 255.0) / _screenTime);
	}
	if (_opacity < 0) {
		_opacity = 0;
	}
	
}