#pragma warning(disable:4996)
#include "utils/game.h"


int main(int argc, char **argv) {
	srand(time(NULL));

	Game* game = new Game;
	GameLoad(game, argv);
	return 0;
}
