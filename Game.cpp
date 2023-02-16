#pragma once
#include "Game.h"
#include <iostream>
#include <memory>
#include "MainGui.h"
#include "StaticText.h"
#include "TemporalText.h"
#include <string>

Game::Game() {
	//std::cout << "Game instance created" << std::endl;
}

Game::~Game() {
	//std::cout << "Game instance destroyed" << std::endl;
}

void Game::Initialize(const char* title) {
	InitWindow(800, 600, title);
	HideCursor();
	// SetExitKey(0); // Disables ESC_KEY for Exit
	SetTargetFPS(60);

	// Crea Main GUI
	_mainGui = std::make_unique<MainGUI>();

	// Crea cursor
	_cover = std::make_unique<MouseCover>(RAYWHITE);

	// Crea pelotas
	_blueBall = std::make_unique<Ball>(Vector2{ 400, 100 }, 20.0f, BLUE, true);
	_redBall = std::make_unique<Ball>(Vector2{ 100, 500 }, 20.0f, RED, true);
	_yellowBall = std::make_unique<Ball>(Vector2{ 700, 500 }, 20.0f, YELLOW, true);

	_ballList.push_back(_blueBall.get());
	_ballList.push_back(_redBall.get());
	_ballList.push_back(_yellowBall.get());

	// Crea un comportamiento
	followMouse = std::make_unique<FollowMouse>();

	// Añade el comportamiento a cada pelota (solo referencia)
	for (Ball* ball : _ballList) {
		ball->AddBehaviour(followMouse.get());
	}
}

void Game::Shutdown() {
	CloseWindow();
}

void Game::RunLoop() {
	while (!WindowShouldClose()) {
		ProcessInput();
		float deltaTime = GetFrameTime();
		UpdateGame(deltaTime);
		_mainGui->Update(deltaTime);
		DrawObjects();
	}
}

void Game::DrawObjects() {
	BeginDrawing();
	ClearBackground(BLACK);

	_cover->Draw();

	for (Ball* ball : _ballList) {
		ball->Draw();
	}
	;
	_mainGui->Draw();
	EndDrawing();
}

void Game::ProcessInput() {
	if (IsKeyPressed(KEY_X)) {
		// std::cout << "Toggle Trail" << std::endl;
		for (Ball* ball : _ballList) {
			ball->ToggleTrail();
		}
	}

	if (IsKeyDown(KEY_UP)) {
		TemporalText* textElement = _mainGui->TrailLengthText.get();
		int trailLength = _ballList[0]->GetTrailLength();
		
		for (Ball* ball : _ballList) {
			ball->SetTrailLength(trailLength + 1);
		}

		textElement->SetLabel("Trail Length: " + std::to_string(trailLength + 1));
	}

	if (IsKeyDown(KEY_DOWN)) {
		TemporalText* textElement = _mainGui->TrailLengthText.get();
		int trailLength = _ballList[0]->GetTrailLength();

		for (Ball* ball : _ballList) {
			ball->SetTrailLength(trailLength - 1);
		}
		textElement->SetLabel("Trail Length: " + std::to_string(trailLength - 1));
	}
}

void Game::UpdateGame(float deltaTime) {
	_cover->Update();

	for (Ball* ball : _ballList) {
		ball->Update(deltaTime);
	}
}