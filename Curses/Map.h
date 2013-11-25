#ifndef MAP_H
#define MAP_H

#include "Common.h"

class Tile;

class Map
{
	public:
		Map();
		~Map();

	private:
		std::vector< std::vector<Tile*> > tiles;
};

#endif