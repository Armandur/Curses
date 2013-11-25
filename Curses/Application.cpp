#include "Common.h"

#include <curses.h>
#include <panel.h>

/*void startUp();
void cleanUp();

int main()
{

	Entity e;

	std::cin.get();

	startUp();

	Grid<char> g(25, 80, '.');

	bool running = true;

	char ch;

	int x, y;

	x = y = 5;

	while(running)
	{
		ch = getch();

		switch(ch)
		{
			case '8' :
			case 'i' :
						y--;
				break;
			
			case '2' :
			case 'k' :
						y++;
				break;
			
			case '4' :
			case 'j' :
						x--;
				break;

			case '6' :
			case 'l' :
						x++;
				break;

			default :
				break;
		}

		for(int i = 0; i < g.getHeight(); i++)
		{
			for(int j = 0; j < g.getWidth(); j++)
			{
				mvaddch(i, j, g(i, j));
			}
		}

		mvaddch(y, x, '@');

		refresh();
	}

	cleanUp();
	std::cin.get();
	return 0;
}

void startUp()
{
	initscr();
	keypad(stdscr, 1);
	noecho();
	raw();
	curs_set(0);
}

void cleanUp()
{
	endwin();
}*/


int main()
{
	Entity player;
	boost::shared_ptr<PhysicalComponent> p_phys;

	player.addComponent("phys", p_phys);

	EntityMessage message;
	message.addArgument("type", "move");
	message.addArgument("posX", (double)10.0);
	message.addArgument("posY", (double)5.0);

	std::cout << message.toString();

	std::cin.get();

	return 0;
}