#include "Agent.h"


Agent::Agent(float dx, float dy, Cell cell, vector<Cell> cells)
{
	cellL = dx; cellW = dy; inCell = cell; allCells = cells;
	POS = cell.cellMP();
	cellsOccupied.push_back(inCell);
	cell.setOccupied(0);
}

void Agent::addAllCells(vector<Cell> c) {
	allCells = c;
}

void Agent::setArea(float a) {
	AREA = a;
}

void Agent::clear() {
	try{ 
		allCells.clear(); 
	}
	catch (exception e) {
		cout << "error in vector clearing 1" << endl;
		//blank vector
	}
	try {
		cellsOccupied.clear();
	}
	catch (exception e) {
		cout << "error in vector clearing 2" << endl;
		//blank vector
	}
}

Cell Agent::getInCell() { return inCell; }

void Agent::setInCell(Cell G) { 
	cellL = G.L; cellW = G.W;
	POS = G.cellMP();
	inCell = G; 
	cellsOccupied.push_back(G); 
}


void Agent::initMove() {
	float sum = totalAreaOccupied();
	int brkRec = 10000;
	int itr = 0;	
	if (sum >= AREA) {
		SUCCESS = 1;
	}
	cout << "initiating MOVE..." << sum << ", " << AREA << endl;
	if (sum < AREA) {
		int t=move(0);
		sum = totalAreaOccupied();
		if (t == 0) {
			cout << "(BREAK) id 0 was returned" << endl;
			SUCCESS = 0;
		}
		if (itr > brkRec) {
			cout << "(BREAK) iteration limit reached" << endl;
			SUCCESS = 0;
		}			
		if (sum >= AREA) {
			cout << "(BREAK) area limit reached" << endl;
			SUCCESS = 1;
		}		
		cout  << itr << "(ITERATE) sum is now : " << sum << ", " << AREA << endl;
		itr++;
	}
	cout << "\n\n\n SUCCESS: " << SUCCESS << endl;
	if (SUCCESS == 0) {
		clear();
		initMove();
	}
}
float Agent::totalAreaOccupied() {
	float sumx = 0;
	if (cellsOccupied.size() < 1) {
		cout << "return 0 from sum " << endl;
		return sumx;
	}
	for (unsigned int i = 0; i < cellsOccupied.size(); i++) {
		sumx += cellsOccupied[i].getArea();
	}
	cout << "return sumx from sum " << sumx << endl;
	return sumx;
}

int Agent::move(int rec) {
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
	if (rec < allCells.size()) {
		rec++;
		dontRepeat(E, rec);
	}
	if (E.cellId == 0) { return 0; }
	else { return 1; }
}

void Agent::dontRepeat(Cell F, int rec) {
	if (F.cellId != 0 && rec < 100) { setInCell(F); }
	
	if ((totalAreaOccupied() - AREA)<0) { move(rec); }
	else { SUCCESS = 1; }
	
}

Cell Agent::getCell(ofVec3f p) {
	Cell req = allCells[0];
	int i = 0; bool T = 0;
	while (T == 0 && i < allCells.size()-1) {
		Cell got = allCells[i];
		bool t = got.contains(p);
		if (t == true) {
			int sum = 0;
			for (int j = 0; j < cellsOccupied.size(); j++) {
				if (cellsOccupied[j].cellId == got.cellId) {
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









