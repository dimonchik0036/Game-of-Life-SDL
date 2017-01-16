#include "life.h"


static int check_neighbor(int x, int y);

static int adjustment_x(int x);

static int adjustment_y(int y);


void life_process()
{
	for (int x = 0; x < X_FIELD_SIZE; ++x)
	{
		for (int y = 0; y < Y_FIELD_SIZE; ++y)
		{
			switch (check_neighbor(x, y))
			{
			case NEW_LIFE:
				if (get_playing_field()[y][x] == false)
				{
					push_stack(x, y);
				}

				break;
			case LIFE:

				break;
			default:
				if (get_playing_field()[y][x])
				{
					push_stack(x, y);
				}

				break;
			}
		}
	}
}

void life_render()
{
	while (get_size_stack())
	{
		Point point = pop_stack();

		if (get_playing_field()[point.y][point.x])
		{
			recolor_block_playing_field(BackgroundColor, point.x, point.y);
		}
		else
		{
			recolor_block_playing_field(BlockColor, point.x, point.y);
		}
	}
}

static int check_neighbor(int x, int y)
{
	int count = 0;

	if (get_playing_field()[y][x])
	{
		--count;
	}

	for (int j = -1; j <= 1; ++j)
	{
		for (int i = -1; i <= 1; ++i)
		{
			if (get_playing_field()[adjustment_y(y + i)][adjustment_x(x + j)])
			{
				++count;
			}
		}
	}

	return count;
}

static int adjustment_x(int x)
{
	if (x < 0)
	{
		x += X_FIELD_SIZE;

		return x;
	}

	if (x >= X_FIELD_SIZE)
	{
		x -= X_FIELD_SIZE;

		return x;
	}

	return x;
}

static int adjustment_y(int y)
{
	if (y < 0)
	{
		y += Y_FIELD_SIZE;

		return y;
	}

	if (y >= Y_FIELD_SIZE)
	{
		y -= Y_FIELD_SIZE;

		return y;
	}

	return y;
}