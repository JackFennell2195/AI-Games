#pragma once
const int GRID_SIZE = 50;
const int TILE_WIDTH = 32;
const int TILE_HEIGHT = 32;
const int TOTAL_TILES = 2500;

class Tile 
{
public:
	Tile();
	~Tile();
	int map[GRID_SIZE][GRID_SIZE];
	void createGrid();

private:
	
};