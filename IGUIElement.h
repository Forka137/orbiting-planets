#pragma once
#include <raylib.h>
#include <string>

class IGUIElement {
public:
	IGUIElement() {}
	~IGUIElement() {}

	virtual void Draw() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Show() = 0;
	virtual void Hide() = 0;
};