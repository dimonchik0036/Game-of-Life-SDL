#include "input.h"
#include "life.h"


static bool keysHeld[MAX_KEYS];

static int lastXCoordinates = 0;
static int lastYCoordinates = 0;

static int speed = 50;


static void check_keycode(int keycode);

static void speed_up();

static void speed_down();


void init_keys_state()
{
	for (int k = 0; k < MAX_KEYS; ++k)
	{
		keysHeld[k] = false;
	}
}

void handle_keydown(int keycode)
{
	check_keycode(keycode);

	keysHeld[keycode] = true;
}

void handle_keyup(int keycode)
{
	check_keycode(keycode);

	keysHeld[keycode]= false;
}

bool key_held(int keycode)
{
	return  keysHeld[keycode];
}

static void check_keycode(int keycode)
{
	if (keycode >= MAX_KEYS || keycode < 0)
	{
		printf("Keycode %d is out of range.\nForce quit.\n", keycode);
		exit(1);
	}
}

void set_coordinates(int x, int y)
{
	lastXCoordinates = x;
	lastYCoordinates = y;
}

Point get_coordinates()
{
	return (Point) { lastXCoordinates, lastYCoordinates };
}

void check_keys(ProgramState *state, int keycode)
{
	switch (*state)
	{
	case Begin:
		if (SDLK_SPACE == keycode)
		{
			*state = Play;

			break;
		}

		if (SDLK_ESCAPE == keycode)
		{
			clear_playing_field();

			break;
		}

		break;
	case Play:
		if (SDLK_SPACE == keycode)
		{
			*state = Begin;

			break;
		}

		break;
	/*case Pause:
		if (SDLK_SPACE == keycode)
		{
			*state = Play;

			break;
		}

		if (SDLK_ESCAPE == keycode)
		{
			*state = Begin;

			break;
		}

		break;*/
	}

	if (SDLK_KP_MINUS == keycode)
	{
		speed_down();
	}

	if (SDLK_KP_PLUS == keycode)
	{
		speed_up();
	}
}

int get_speed()
{
	return speed;
}

static void speed_up()
{
	if (speed - BOOST_SPEED >= 0)
	{
		speed -= BOOST_SPEED;
	}
}

static void speed_down()
{
	speed += BOOST_SPEED;
}