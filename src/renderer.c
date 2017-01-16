#include "renderer.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_gfxPrimitives.h"
#include "window.h"
#include "imageloader.h"


void draw_image_coord(SDL_Surface *surface, Point dst) 
{
	draw_image_coord_offset(surface, dst, (Point) { 0, 0 });
}

void draw_image_coord_offset(SDL_Surface *surface, Point dst, Point offset)
{
	SDL_Rect dstrect;

	dstrect.x = dst.x + offset.x;
	dstrect.y = dst.y + offset.y;

	SDL_BlitSurface(surface, NULL, get_screen(), &dstrect);
}

void draw_block_offset(Color color, Point dst, Point offset)
{
	switch (color)
	{
	case BlockColor:
		draw_image_coord_offset(get_block_image(), dst, offset);
		break;
	case BackgroundColor:
		draw_background_block_offset(dst, offset);
		break;
	}
}

void draw_background_block_offset(Point dst, Point offset)
{
	SDL_Rect dstrect;
	SDL_Rect imgrect = { 0, 0, 12, 12 };

	dstrect.x = dst.x + offset.x;
	dstrect.y = dst.y + offset.y;

	SDL_BlitSurface(get_background_image(), &imgrect, get_screen(), &dstrect);
}

void draw_background()
{
	clear_screen(0x00, 0x00, 0x00, 0xFF);
	draw_image_coord(get_background_image(), (Point) { 0, 0 });
}