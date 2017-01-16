#pragma once

#include "SDL.h"
#include <stdbool.h>


#define MAX_KEYS 323


/* Инициализирует обработчик нажатий */
void init_keys_state();

/* Обработчик нажатия кнопки */
void handle_keydown(int keycode);

/* Обработчик отпуская кнопки */
void handle_keyup(int keycode);

/* Проверяет, нажата ли заданная кнопка. */
bool key_held(int keycode);