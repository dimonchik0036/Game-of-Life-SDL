#pragma once

#include <stdbool.h>
#include "SDL.h"

/* Инициализирует окно */
bool init_window(const char* title, int width, int height);

/* Уничтожает окно */
void dispose_window(void);

/* Возвращает указатель на окно */
SDL_Surface* get_screen(void);

/* Заполнение экрана заданным цветом */
void clear_screen(int r, int g, int b, int a);

/* Используется двойная буферизация. обменивает буферы */
void flip_screen(void);
