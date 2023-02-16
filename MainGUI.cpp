#pragma once
#include "MainGUI.h"
#include "TemporalText.h"
#include "StaticText.h"

MainGUI::MainGUI() {
	// Añadir elementos de esta GUI
	// Inicializa elementos
	// Text, size, position, time (s)
	TrailLengthText = std::make_unique<TemporalText>("Trail Length: 30", 24, Vector2{ 270, 50 });
	WelcomeText = std::make_unique<TemporalText>("Orbitas v3", 16, Vector2{ 20, 20 }, 3.0);
	SignatureText = std::make_unique<TemporalText>("Forka137", 16, Vector2{ 700, 20 }, 3.0);

	// Text, size, position
	ControlsText = std::make_unique<StaticText>(" Up / Down: Increase/Decrease trail", 16, Vector2{ 440, 580 });
	ControlsText2 = std::make_unique<StaticText>("X : Toggle trail", 16, Vector2{ 20, 580 });

	TrailLengthText->Hide();
	ControlsText->Opacity = 220;
	ControlsText2->Opacity = 220;

	//_elements solo recibe una referencia de cada uno.
	_elements.push_back(TrailLengthText.get());
	_elements.push_back(WelcomeText.get());
	_elements.push_back(SignatureText.get());
	_elements.push_back(ControlsText.get());
	_elements.push_back(ControlsText2.get());
}

MainGUI::~MainGUI() {

}
