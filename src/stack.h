#pragma once

#include "playingfield.h"
#include "renderer.h"

#define MAX_SIZE_STACK 3969

typedef struct {
	Point stack[MAX_SIZE_STACK];
	int size;
} Stack; 


void init_stack();

void push_stack(int x, int y);

Point pop_stack();

Point peek_stack();

int get_size_stack();