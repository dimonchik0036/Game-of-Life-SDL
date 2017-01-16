#pragma once

#include "SDL.h"
#include <stdbool.h>
#include "renderer.h"


#define MAX_KEYS 323
#define MAX_MOUSE_KEYS 2

/* Инициализирует обработчик нажатий */
void init_keys_state();

/* Обработчик нажатия кнопки */
void handle_keydown(int keycode);

/* Обработчик отпуская кнопки */
void handle_keyup(int keycode);

/* Проверяет, нажата ли заданная кнопка. */
bool key_held(int keycode);

void set_coordinates(int x, int y);

Point get_coordinates();