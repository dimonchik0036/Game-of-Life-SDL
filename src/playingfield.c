#include "playingfield.h"
#include <stdbool.h>



static bool playingField[Y_FIELD_SIZE][X_FIELD_SIZE];


static void draw_block_in_playing_field(enum Color color, int x, int y);


void init_playing_field() 
{
	for (int y = 0; y < Y_FIELD_SIZE; ++y)
	{
		for (int x = 0; x < X_FIELD_SIZE; ++x)
		{
			playingField[y][x] = false;
		}
	}
}

void restructuring_playing_field()
{
	for (int y = 0; y < Y_FIELD_SIZE; ++y)
	{
		for (int x = 0; x < X_FIELD_SIZE; ++x)
		{
			switch (playingField[y][x])
			{
			case true:
				draw_block_in_playing_field(BlockColor, x, y);

				break;
			case false:
				draw_block_in_playing_field(BackgroundColor, x, y);

				break;
			}
		}
	}
}

void clear_playing_field()
{
	for (int y = 0; y < Y_FIELD_SIZE; ++y)
	{
		for (int x = 0; x < X_FIELD_SIZE; ++x)
		{
			if (playingField[y][x] != false)
			{
				draw_block_in_playing_field(BackgroundColor, x, y);

				playingField[y][x] = false;
			}
		}
	}
}

static void draw_block_in_playing_field(Color color, int x, int y)
{
	draw_block_offset(color, (Point) { x * X_BLOCK_SIZE, y * Y_BLOCK_SIZE }, (Point) { X_FIELD_OFFSET, Y_FIELD_OFFSET });
}

void recolor_block_playing_field(Color color, int x, int y)
{
	if ((0 <= x) && (x < X_FIELD_SIZE) && (0 <= y) && (y < Y_FIELD_SIZE))
	{
		switch (color)
		{
		case BlockColor:
			if (playingField[y][x] == false)
			{
				draw_block_in_playing_field(color, x, y);

				playingField[y][x] = true;
			}

			break;
		case BackgroundColor:
			if (playingField[y][x] == true)
			{
				draw_block_in_playing_field(color, x, y);

				playingField[y][x] = false;
			}

			break;
		}
	}
}

void created_playing_field()
{
	if (key_held(SDL_BUTTON_RIGHT))
	{
		int x = X_FIELD_OFFSET + get_coordinates().x;
		int y = Y_FIELD_OFFSET + get_coordinates().y;

		recolor_block_playing_field(BackgroundColor, ((x == X_BLOCK_SIZE * X_FIELD_SIZE) ? x - 1 : x) / X_BLOCK_SIZE, ((y == X_BLOCK_SIZE * X_FIELD_SIZE) ? y - 1 : y) / Y_BLOCK_SIZE);

		return;
	}

	if (key_held(SDL_BUTTON_LEFT))
	{
		int x = X_FIELD_OFFSET + get_coordinates().x;
		int y = Y_FIELD_OFFSET + get_coordinates().y;

		recolor_block_playing_field(BlockColor, ((x == X_BLOCK_SIZE * X_FIELD_SIZE) ? x - 1 : x) / X_BLOCK_SIZE, ((y == X_BLOCK_SIZE * X_FIELD_SIZE) ? y - 1 : y) / Y_BLOCK_SIZE);

		return;
	}
}