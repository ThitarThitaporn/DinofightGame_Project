#include"stdafx.h"
#include"Game.h"


int main()
{
	srand((unsigned)time(NULL));

	Game game;
	//backgroud
	
	while (game.getWindow().isOpen())
	{

		game.update();
		game.render();
	}
	//End of application 
	return 0;
}