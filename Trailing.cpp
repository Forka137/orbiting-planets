#pragma once
#include "Trailing.h"
#include <iostream>
#include "raymath.h"

Trailing::Trailing(int trailLength) {
	_length = trailLength;
	_lastPoints.reserve(_length);
	for (int i = 0; i < _length; i++) {
		// Creates points outside the view
		TrailPoint point = { {-50.0f, -50.0f}, _size };
		_lastPoints.push_back(point);
	}
};

Trailing::~Trailing() {
	// std::cout << "Trail destroyed" << std::endl;
};
/// <summary>
/// Guarda la posición y velocidad normalizada de la pelota segun la frecuencia por frame.
/// Utiliza un pequeño factor de 1.4 - speed, donde el valor máximo de speed es 1. así el trail
/// nunca se hará más pequeño que _size * 0.4
/// </summary>
void Trailing::Update(Ball* ball, float deltaTime) {
	_frameCounter += 1;

	if (_frameCounter > int(1.0f / _frequency)) {
		float speed = Vector2Length(ball->velocity) / ball->GetMaxSpeed();

		_lastPoints[_counter].position = ball->GetPosition();
		_lastPoints[_counter].size = _size * (1.4f - speed);
		Count();
		_frameCounter = 0;
	}
	//Draw(ball->GetColor());
}

// Cuenta los frames que pasan para dibujar un punto de trail
void Trailing::Count() {
	_counter += 1;
	// con _length se sale del rango
	if (_counter > _lastPoints.size() - 1) {
		_counter = 0;
	}
}

void Trailing::Draw(Color color) {
	for (TrailPoint p : _lastPoints) {
		DrawCircle((int)p.position.x, (int)p.position.y, p.size, { color.r, color.g, color.b, _opacity });
	}
}