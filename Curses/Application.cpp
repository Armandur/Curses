#include <iostream>
#include "curses.h"
#include "panel.h"
#include "Map.h"

void startUp();
void cleanUp();

int main()
{
	startUp();
	bool running = true;

	char player = '@';
	Map map(10, 20, '.');

	int x, y;

	x = y = 10;

	int ch;

	while(running)
	{

		ch = getch();

		switch(ch)
		{
			case 'w' :
			case 'u' :
					y--;
				break;
			case 's' :
			case 'k' :
				y++;
				break;
			case 'a' :
			case 'j' :
					x--;
				break;
			case 'd' :
			case 'l' :
					x++;
				break;
			default:
				break;
		}
		map.draw(5, 5);
		mvaddch(y, x, player);
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
}

void cleanUp()
{
	endwin();
}