#pragma once
#include <vector>
#include "IGUIElement.h"
#include <memory>

class BaseGUI
{
public:
	BaseGUI(); // Declare all the GUI items here
	~BaseGUI();
	
	void Update(float deltaTime);
	void AddElement(IGUIElement* element);

	void Draw();
	void Show();
	void Hide();
	void ToggleShow();

	
protected:
	std::vector<IGUIElement*> _elements;
	bool _shouldDraw = true;
};

