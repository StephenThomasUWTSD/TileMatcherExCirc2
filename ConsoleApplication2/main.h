#pragma once
//libs etc
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <ctime>
#include <algorithm>
#include <vector>
//source files
#include "glut.h"
#include "box.h"
#include "gameLoop.h"
#include "vector.h"



//main functions
using namespace std;
void init(void);
void display(void);
void drawHouse(void);
void drawBoxes(void);
//class instances
Loop game;
