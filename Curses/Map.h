#ifndef MAP_H
#define MAP_H

#include <vector>

#include "curses.h"

class Map
{
	public:
		Map();
		Map(int height, int width, char background);
		~Map();

		void draw(int offsetY, int offsetX);
	private:
		int height, width;
		void createMap();
		void createMap(char background);

		std::vector<std::vector<char>> map;
};

#endif