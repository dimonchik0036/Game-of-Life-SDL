#pragma once

#include <stdbool.h>


typedef enum
{
	GameBeginState,
	GamePlayState,
	GamePauseState,
	GameEndState
} GameState;

typedef struct
{
	GameState gameState;
} Game;


void game_init(Game *game);

void game_tick(Game *game);

void game_render(Game *game);