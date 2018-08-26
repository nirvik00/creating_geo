#pragma once
#include "ofMain.h"
#include "Cell.h"
#include <vector>
#include <string>

class Cell
{
public:
	float X, Y, L, W;
	int cellId;
	int indX, indY;
	int occupied;
	
	Cell() {};
	Cell(int, float, float, float, float, int , int);

	ofVec3f cellMP();

	void draw();
	void display();
	bool contains(ofVec3f);

	void setOccupied(int);
	int Cell::getOccupied();
};

