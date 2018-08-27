#include "Agent.h"

void Agent::addAllSysCells(vector<Cell> t) {
	for (unsigned int i = 0; i < t.size(); i++) {
		sysCellsOccupied.push_back(t[i]);
	}
}

void Agent::addAllCells(vector<Cell> c) {
	allCells = c;
}

void Agent::setArea(float a) { AREA = a; }

void Agent::clear() {
	for (int i = 0; i < cellsOccupied.size(); i++) {
		int a = cellsOccupied[i].cellId;
		int t = -1;
		for (int j = 0; j < sysCellsOccupied.size(); j++){
			int b = sysCellsOccupied[j].cellId;
			if (a == b) {
				t = j;
				break;
			}
		}
		if (t > -1) {
			sysCellsOccupied.erase(sysCellsOccupied.begin()+t);
		}
	}
	cellsOccupied.clear();
}

Cell Agent::getInCell() { return inCell; }

void Agent::setInCell(Cell G) {
	cellL = G.L; cellW = G.W;
	POS = G.cellMP();
	inCell = G; 
	cellsOccupied.push_back(G); 
	sysCellsOccupied.push_back(G);
}

void Agent::initMove(int recNum) {
	float sum = totalAreaOccupied();
	int brkRec = 10000;
	int itr = 0;	
	if (sum >= AREA) {
		SUCCESS = 1;
	}
	//cout << "\ninitiating MOVE..." << sum << ", " << AREA << endl;
	if (sum < AREA) {
		cout << sum << endl;
		int t=move(0);
		if (t == 0) { SUCCESS = 0; }
		if (itr > brkRec) { SUCCESS = 0; }
		
		sum = totalAreaOccupied();
		if (sum >= AREA) { SUCCESS = 1; }
		
		itr++;
	}
	//cout << "SUCCESS: " << SUCCESS << endl;
	if (SUCCESS == 0 && recNum<100) {
		recNum++;
		clear();
		initMove(recNum);
	}
}

float Agent::totalAreaOccupied() {
	float sumx = 0;
	if (cellsOccupied.size() < 1) { return sumx;}
	for (unsigned int i = 0; i < cellsOccupied.size(); i++) {
		sumx += cellsOccupied[i].getArea();
	}
	return sumx;
}

int Agent::move(int rec) {
	/*
	* Find the direction - stochastic
	* coordinates(x,y,z) of Move by 1 grid (mid-point) in desired direction
	* figure out what cell that position refers to
	* if the cell is free - success
	* else repeat move
	*/
	//cout << "moving : " << rec << "; " << totalAreaOccupied() << endl;
	Cell E = allCells[0];
	int x = (int)ofRandom(0, 4);
	ofVec3f pos = POS;
	if (x == 0) { 
		//cout << "left" << endl;
		pos = { pos.x - cellL, pos.y, 0 };
	}
	else if (x == 1) { 
		//cout << "right" << endl;
		pos = { pos.x + cellL, pos.y, 0 };
	}
	else if (x == 2) { 
		//cout << "up" << endl;
		pos = { pos.x, pos.y - cellW, 0 };
	}
	else { 
		//cout << "down" << endl;
		pos = { pos.x, pos.y + cellW, 0 };
	}
	E= getCell(pos);
	if (rec < 100) {
		rec++;
		dontRepeat(E, rec);
	}
	if (E.cellId == 0) { return 0; }
	else { return 1; }
}

void Agent::dontRepeat(Cell F, int rec) {
	/*
	* since in getCell function cell 0 is returned if not free
	* success=false & move again
	* if the returned cell is not 0, success 
	* check also is the cumulative area is achieved or not
	*/
	if (F.cellId != 0 ) { setInCell(F); }	
	if (totalAreaOccupied() < AREA) { SUCCESS = 0; move(rec); }
	else { SUCCESS = 1; }	
}

Cell Agent::getCell(ofVec3f p) {
	/*
	* find the cell that refers to the position
	* check if it is free
	* else return cell 0
	*/
	Cell req = allCells[0];	
	int i = 0; bool T = 0;
	while (T == 0 && i < allCells.size()-1) {
		Cell got = allCells[i];
		bool t = got.contains(p);
		if (t == true) {
			int sum = 0;
			for (int j = 0; j < sysCellsOccupied.size(); j++) {
				if (sysCellsOccupied[j].cellId == got.cellId) {
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









