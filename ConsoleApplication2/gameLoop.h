#pragma once
#include "main.h"
#include "box.h"
#include <vector>
class Loop
{
private:
	void InitialiseBoxPositions(int, int);
	void GenerateBoxes(int);
	void GenerateBoxPositions(void);
	struct BoxPositions {
		int x, y;
	};
	bool positionsGenerated;
public:
	Loop();
	~Loop();
	void ShuffleBoxes(void);
	float randColour();
	std::vector<Box> boxes;
	std::vector<BoxPositions> boxPositions;
	const int GRID_WIDTH = 6;
	const int GRID_HEIGHT = 6;
};

