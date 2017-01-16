#include "stack.h"


static Stack stack;


void init_stack()
{
	stack.size = 0;
}

void push_stack(int x, int y)
{
	if (stack.size <  MAX_SIZE_STACK)
	{
		stack.stack[stack.size].x = x;
		stack.stack[stack.size].x = y;

		++stack.size;
	}
	else 
	{
		printf("\nError push stack\n");
		exit(1);
	}
}

Point pop_stack()
{
	if (stack.size > 0)
	{
		--stack.size;

		return stack.stack[stack.size];
	}
	else
	{
		printf("\nError pop stack\n");
		exit(1);
	}
}

Point peek_stack()
{
	if (stack.size > 0)
	{
		return stack.stack[stack.size];
	}
	else
	{
		printf("\nError peek stack\n");
		exit(1);
	}
}

int get_size_stack()
{
	return stack.size;
}