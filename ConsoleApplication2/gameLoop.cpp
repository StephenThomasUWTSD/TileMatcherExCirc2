#include "gameLoop.h"



Loop::Loop()
{
	GenerateBoxes(GRID_WIDTH * GRID_HEIGHT);
	InitialiseBoxPositions(GRID_WIDTH, GRID_HEIGHT);
	positionsGenerated = false;
}


Loop::~Loop()
{
}

void Loop::InitialiseBoxPositions(int width, int height) {
	int x = 0, z = 0;

	for (size_t boxIndex = 0; boxIndex < boxes.size(); boxIndex++)
	{
		boxes[boxIndex].x = x;
		boxes[boxIndex].y = 0;
		boxes[boxIndex].z = z;

		x++;
		if (x >= width)
		{
			x = 0;
			z++;
		}
	}
}

void Loop::GenerateBoxes(int numBoxes) {
	for (int boxIndex = 0; boxIndex < numBoxes; boxIndex += 2)
	{
		float r = randColour(), g = randColour(), b = randColour();
		Box first = { 0,0,0,r,g,b };
		Box second = { 0,0,0,r,g,b };

		boxes.push_back(first);
		boxes.push_back(second);
	}
}

void Loop::GenerateBoxPositions() {
	for (int x = 0; x < GRID_WIDTH; x++)
	{
		for (int z = 0; z < GRID_HEIGHT; z++)
		{
			boxPositions.push_back({ x, z });
		}
	}
}

float Loop::randColour()
{
	return (double)rand() / (RAND_MAX + 1.0);
}