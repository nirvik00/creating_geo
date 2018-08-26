#pragma once
#include "ofMain.h"
#include "Cell.h"

#include <vector>
#include <string>

class Agent
{
public:
	vector<Cell> allCells;
	vector<Cell> cellOccupied;
	float cellL, cellW;
	ofVec3f POS;
	Cell inCell;

	Agent(){}

	Agent(float, float, Cell, vector<Cell>);

	void addAllCells(vector<Cell>);

	void clear();
	Cell getInCell();
	void setInCell(Cell);

	void move();

	void dontRepeat(Cell);

	Cell getCell(ofVec3f);

};

