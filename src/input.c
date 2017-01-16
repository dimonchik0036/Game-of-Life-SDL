#include "input.h"


static bool keysHeld[MAX_KEYS];


static void check_keycode(int keycode);


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
	if (keycode >= MAX_KEYS)
	{
		printf("Keycode %d is out of range.\nForce quit.\n", keycode);
		exit(1);
	}
}