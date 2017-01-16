#include "game.h"
#include "window.h"
#include "renderer.h"
#include "input.h"
#include "main.h"
#include "playingfield.h"
#include "stack.h"


void game_tick(Game *game)
{
	switch (game->gameState)
	{
	case GameBeginState:

		break;

	case GamePlayState:


		break;

	case GameEndState:
		break;
	}
}

void game_render(Game *game)
{
	switch (game->gameState)
	{
	case GameBeginState:
		break;

	case GamePlayState:
		
		break;

	case GameEndState:
		break;
	}
}

void game_init(Game *game)
{
	init_playing_field();

	init_keys_state();

	init_stack();

	draw_background();
}