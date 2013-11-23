#include <vector>
#include "Map.h"

Map::Map()
{
	this->height = 25;
	this->width = 80;

	createMap();
}

Map::Map(int height, int width, char background)
{
	this->height = height;
	this->width = width;

	createMap();
}

void Map::draw(int offsetY, int offsetX)
{
	for(int i = 0; i < map[i].size(); i++)
	{
		for(int j = 0; j < map[i][j]; j++)
		{
			mvaddch(i+offsetY, j+offsetX, map[i][j]);
		}
	}
}

void Map::createMap()
{
	map.resize(this->width , std::vector<char>(this->height, ' '));
}

void Map::createMap(char background)
{
	map.resize(this->width , std::vector<char>(this->height, background));
}

Map::~Map()
{
}
