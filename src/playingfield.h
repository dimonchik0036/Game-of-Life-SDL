#pragma once

#include "renderer.h"
#include "input.h"
#include "stack.h"


#define X_FIELD_SIZE 63
#define Y_FIELD_SIZE 63

#define X_FIELD_OFFSET 0
#define Y_FIELD_OFFSET 0

#define X_BLOCK_SIZE 11
#define Y_BLOCK_SIZE 11


void init_playing_field();

void restructuring_playing_field();

void recolor_block_playing_field(enum Color color, int x, int y);

void created_playing_field();

void clear_playing_field();

bool (* get_playing_field())[Y_FIELD_SIZE];

void create_base_field(int number);