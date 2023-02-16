#pragma once
#include "raylib.h"
#include "Game.h"

int main() {
	Game game;
	game.Initialize("Orbitas");
	game.RunLoop();
	return 0;
}