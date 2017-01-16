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

void draw_background()
{
	clear_screen(0x00, 0x00, 0x00, 0xFF);
	draw_image_coord(get_background_image(), (Point) { 0, 0 });
}