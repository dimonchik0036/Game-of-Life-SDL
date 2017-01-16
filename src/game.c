#include "game.h"
#include "window.h"
#include "renderer.h"
#include "input.h"
#include "main.h"
#include "playingfield.h"
#include "stack.h"
#include "life.h"


void game_tick(Game *game)
{
	switch (game->gameState)
	{
	case GameBeginState:

		break;

	case GamePlayState:
		life_process();

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
		life_render();
		SDL_Delay(get_speed());

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

	game->gameState = GamePlayState;
}