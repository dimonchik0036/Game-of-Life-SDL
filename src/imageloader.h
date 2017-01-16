#pragma once

#include <SDL.h>
#include <SDL_image.h>


#define DIR_IMAGE "image/"


void load_images();

void destroy_image();

SDL_Surface* get_block_image();

SDL_Surface* get_background_image();