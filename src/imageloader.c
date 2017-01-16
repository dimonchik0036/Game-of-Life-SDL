#include "imageloader.h"


SDL_Surface *background;
SDL_Surface *blocks;


static SDL_Surface *load_image(char *filename);


static SDL_Surface *load_image(char *filename)
{
	SDL_Surface *inputImage = NULL;
	SDL_Surface *resultImage = NULL;

	inputImage = IMG_Load(filename);

	if (inputImage != NULL)
	{
		resultImage = SDL_DisplayFormatAlpha(inputImage);

		SDL_FreeSurface(inputImage);
	}
	else
	{
		printf("Error loading image %s\nForce quit.\n", filename);

		exit(1);
	}

	return resultImage;
}

void load_images()
{
	background = load_image(DIR_IMAGE  "background.png");
	blocks = load_image(DIR_IMAGE "block.png");
}

void destroy_image()
{
	SDL_FreeSurface(background);
	SDL_FreeSurface(blocks);
}

SDL_Surface* get_block_image()
{
	return blocks;
}

SDL_Surface* get_background_image()
{
	return background;
}