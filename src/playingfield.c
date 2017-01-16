#include "playingfield.h"
#include <stdbool.h>
#include "renderer.h"


static bool playingField[Y_FIELD_SIZE][X_FIELD_SIZE];


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
				draw_block_offset(BlockColor, (Point) { x * 11, y * 11 }, (Point) { X_FIELD_OFFSET, Y_FIELD_OFFSET });
				break;
			case false:
				draw_block_offset(BackgroundColor, (Point) { x * 11, y * 11 }, (Point) { X_FIELD_OFFSET, Y_FIELD_OFFSET });
				break;
			}
		}
	}
}