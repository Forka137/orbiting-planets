#pragma once
#include "StaticText.h"
#include "raylib.h"
#include <iostream>
#include <string>

StaticText::StaticText(const char* label, Vector2 position) {
	_label = label;
	_position = position;
	_fontTtf = LoadFontEx("resources/anonymous_pro_bold.ttf", 11, 0, 256);
}


StaticText::StaticText(const char* label, int fontSize, Vector2 position) {
	_label = label;
	_position = position;
	_fontTtf = LoadFontEx("resources/anonymous_pro_bold.ttf", fontSize, 0, 256);
}

StaticText::~StaticText() {

}

void StaticText::SetLabel(std::string label) {
	Show();
	_label = label;
}

std::string StaticText::GetLabel() {
	return _label;
}

void StaticText::Show() {
	Opacity = 255;
}

void StaticText::Hide() {
	Opacity = 0;
}

void StaticText::Draw() {
	// std::cout << "Dibujando texto" << std::endl;
	if (Opacity > 0) {
		DrawTextEx(_fontTtf, _label.c_str(), _position, (float)_fontTtf.baseSize, 2, { 220, 220, 220, (unsigned char)Opacity });
	}
}

void StaticText::Update(float deltaTime) {
	// Nothing
}
