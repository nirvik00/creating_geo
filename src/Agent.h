#pragma once
#include "ofMain.h"
#include "Cell.h"

#include <vector>
#include <string>

class Agent
{
public:
	vector<Cell> allCells;
	vector<Cell> cellsOccupied;
	float cellL, cellW, AREA;
	ofVec3f POS;
	Cell inCell;
	int SUCCESS=0;

	Agent(){}

	Agent(float, float, Cell, vector<Cell>);
	void clear();
	void addAllCells(vector<Cell>);
	void setArea(float);
	
	Cell getInCell();
	void setInCell(Cell);

	void initMove();
	int move(int);
	void dontRepeat(Cell, int);
	Cell getCell(ofVec3f);
	float totalAreaOccupied();

};

