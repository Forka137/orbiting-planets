#pragma once
#include "raylib.h"
#include "Ball.h"
#include <memory>
#include "FollowMouse.h"
#include "MouseCover.h"
#include "MainGUI.h"
#include <vector>


class Game {
public:
	Game();
	~Game();

	void Initialize(const char* title);
	void RunLoop();
	void Shutdown();

private:
	// El juego es dueño de las pelotas y del comportamiento
	std::unique_ptr<Ball> _redBall;
	std::unique_ptr<Ball> _blueBall;
	std::unique_ptr<Ball> _yellowBall;

	std::unique_ptr<MouseCover> _cover;
	std::unique_ptr<FollowMouse> followMouse;

	std::unique_ptr<MainGUI> _mainGui;
	std::vector<Ball*> _ballList;

	Vector2 _ballPosition = {0};
	Vector2 _mousePosition = {0};
	void ProcessInput();
	void UpdateGame(float deltaTime);
	void DrawObjects();
};