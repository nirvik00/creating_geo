#include "Agent.h"


Agent::Agent(float dx, float dy, Cell cell, vector<Cell> cells)
{
	cellL = dx; cellW = dy; inCell = cell; allCells = cells;
	POS = cell.cellMP();
	cellOccupied.push_back(inCell);
	cell.setOccupied(0);
}

void Agent::addAllCells(vector<Cell> c) {
	allCells = c;
}

void Agent::clear() {
	allCells.clear();
	cellOccupied.clear();
}

Cell Agent::getInCell() { return inCell; }

void Agent::setInCell(Cell G) { 
	cellL = G.L; cellW = G.W;
	POS = G.cellMP();
	inCell = G; 
	cellOccupied.push_back(G); 
	for (int i = 0; i < cellOccupied.size(); i++) {
		cellOccupied[i].setOccupied(1);
		cout << "(Agent)these cells are occupied : " << cellOccupied[i].cellId << endl;
	}
}

void Agent::move() {
	cout << "(Agent) moving from cell: " << inCell.cellId << endl;
	Cell E = allCells[0];
	int x = (int)ofRandom(0, 4);
	ofVec3f pos = POS;
	if (x == 0) { 
		cout << "left" << endl;
		pos = { pos.x - cellL, pos.y, 0 };
	}
	else if (x == 1) { 
		cout << "right" << endl;
		pos = { pos.x + cellL, pos.y, 0 };
	}
	else if (x == 2) { 
		cout << "up" << endl;
		pos = { pos.x, pos.y - cellW, 0 };
	}
	else { 
		cout << "down" << endl;
		pos = { pos.x, pos.y + cellW, 0 };
	}
	E= getCell(pos);
	dontRepeat(E);
}

void Agent::dontRepeat(Cell F) {
	if (F.cellId == 0) {
		cout << "(Agent)repeat avoided at cell id: " << inCell.cellId << endl;
		move();
	}
	else {
		setInCell(F);
	}
}

Cell Agent::getCell(ofVec3f p) {
	Cell req = allCells[0];
	int i = 0; bool T = 0;
	while (T == 0 && i < allCells.size()-1) {
		Cell got = allCells[i];
		bool t = got.contains(p);
		if (t == true) {
			int sum = 0;
			for (int j = 0; j < cellOccupied.size(); j++) {
				if (cellOccupied[j].cellId == got.cellId) {
					sum++;
				}
			}
			if (sum == 0) {
				req = allCells[i];
				T = t;
				break;
			}			
		}
		i++;
	}
	return req;
}









