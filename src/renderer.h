#pragma once

#include <stdbool.h>
#include "SDL.h"


typedef struct
{
	int x;
	int y;
} Point;


void draw_image_coord(SDL_Surface *surface, Point dst);

void draw_image_coord_offset(SDL_Surface *surface, Point dst, Point offset);

void draw_background();