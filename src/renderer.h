#pragma once

#include <stdbool.h>
#include "SDL.h"


typedef struct
{
	int x;
	int y;
} Point;

typedef enum {
	BackgroundColor,
	BlockColor
} Color;


void draw_image_coord(SDL_Surface *surface, Point dst);

void draw_image_coord_offset(SDL_Surface *surface, Point dst, Point offset);

void draw_block_offset(Color color, Point dst, Point offset);

void draw_background_block_offset(Point dst, Point offset);

void draw_background();