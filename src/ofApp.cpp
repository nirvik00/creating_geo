#include "ofApp.h"

ofColor ofApp::colorScheme(int i) {
	if (i == 0) { return ofColor(255, 0, 0, 150); }
	else if (i == 1) { return ofColor(255, 100, 0, 150); }
	else if (i == 2) { return ofColor(100, 200, 50, 150); }
	else if (i == 3) { return ofColor(50, 150, 200, 150); }
	else { return ofColor(100, 100, 250, 150); }
}

void ofApp::colorScheme() {
	COLOR[0] = gui->color0;
	COLOR[1] = gui->color1;
	COLOR[2] = gui->color2;
	COLOR[3] = gui->color3;
	COLOR[4] = gui->color4;
}

void ofApp::init() {
	/*
	* starting point for a generation
	*/
	resetSystem();
	cout << "\n\n\n";
	procOccupiedCells.clear();
	
	/*
	* 1. Create the agents and send them to process for cellular occupation
	* 2. Occupied cells will be updated in the system
	*/

	for (unsigned int i = 0; i < 5; i++) {
		Agent agent = agentProc(agent, i);
		agentVec.push_back(agent);
		for (unsigned int j = 0; j < agent.cellsOccupied.size(); j++) {
			Cell cell = agent.cellsOccupied[j];
			procOccupiedCells.push_back(cell);
		}
	}	
}

int ofApp::findAppropriateCellIndex() {
	cout << "\n\n\n";
	cout << "level 1 start;" << endl;
	cout << "all cells size: "  << CELLS.size() << endl;
	cout << "occupied cells size: " << procOccupiedCells.size() << endl;
	/*
	* from all cells, select a random cell index
	* if it is not in occupied cells
	*** check for min distance to all occupied cells
	*** if this min distance >50 & <100 
	***** return cell index
	*/
	vector<Cell> xCells;
	for (int i = 0; i < CELLS.size(); i++) {
		int t = CELLS[i].cellId;
		int sumx = 0;
		for (int j = 0; j < procOccupiedCells.size(); j++) {
			int e = procOccupiedCells[j].cellId;
			if (t == e) { sumx++; }
		}
		if (sumx == 0) {
			xCells.push_back(CELLS[i]); //cells not occupied
		}
	}
	vector<Cell> yCells;
	if (procOccupiedCells.size() > 0) {
		for (int i = 0; i < xCells.size(); i++) {
			for (int j = 0; j < procOccupiedCells.size(); j++) {
				float d = xCells[i].di(procOccupiedCells[j]);
				if (d < gridLength*1.5 || d < gridWidth*1.5) {
					yCells.push_back(xCells[i]);
				}
			}
		}
	}
	cout << "size of x cells : " << xCells.size() << endl;
	cout << "size of y cells : " << yCells.size() << endl;
	int TRY = -1;
	if (yCells.size() > 0) {
		random_shuffle(yCells.begin(), yCells.end());
		TRY = yCells[0].cellId;
	}
	else {
		random_shuffle(xCells.begin(), xCells.end());
		TRY = xCells[0].cellId;
	}
	cout << "finally initial starting cell id= " << TRY << endl;
	return TRY;
}

Agent ofApp::agentProc(Agent agent, int iter) {
	/*
	* starting point - findAppropriateCell()
	* update all values of the agent: ensure initialization is correct
	*/
	agent.clear();
	int t = findAppropriateCellIndex();
	agent.setInCell(CELLS[t]);
	agent.addAllCells(CELLS);
	agent.addAllSysCells(procOccupiedCells);
	agent.setArea(agentAreaArr[iter]);
	agent.initMove(0);

	float sum = 0; 
	for (int i = 0; i < agent.cellsOccupied.size(); i++) {
		Cell cell = agent.cellsOccupied[i];
		sum += cell.getArea();
	}
	cout << iter << "(end of run) total=" << sum << endl;
	return agent;
}

void ofApp::resetSystem() {
	gridLength = gui->gridLength; 
	gridWidth = gui->gridWidth; 

	agentAreaArr[0] = gui->agentArea1;
	agentAreaArr[1] = gui->agentArea2;
	agentAreaArr[2] = gui->agentArea3;
	agentAreaArr[3] = gui->agentArea4;
	agentAreaArr[4] = gui->agentArea5;

	prevL = gridLength; prevW = gridWidth;
	
	COLOR[0] = gui->color0;
	COLOR[1] = gui->color1;
	COLOR[2] = gui->color2;
	COLOR[3] = gui->color3;
	COLOR[4] = gui->color4;

	grid.clear(); CELLS.clear(); int k = 0; int indX = 0;

	for (unsigned int i = 0; i < ofGetWidth(); i += gridLength) {
		int indY = 0;
		for (unsigned int j = 0; j < ofGetWidth(); j += gridWidth) {
			grid.push_back(ofVec3f(i, j, 0));
			CELLS.push_back(Cell(k, i, j, gridLength, gridWidth, indX, indY));
			indY++; k++;
		}
		indX++;
	}

	for (unsigned int i = 0; i < agentVec.size(); i++) { 
		agentVec[i].clear(); 
	}
	agentVec.clear();
}

void ofApp::setup(){
	srand(unsigned(std::time(0)));
	gridLength = 50;
	gridWidth = 50;
	prevL = gridLength;
	prevW = gridWidth;
	indX = 0;
	indY = 0;
	resetSystem();
}

void ofApp::update(){
	gridLength = gui->gridLength; gridWidth = gui->gridWidth;
	if (prevL != gridLength || prevW != gridWidth) { resetSystem(); }
}

void ofApp::draw(){
	ofBackground(255); ofSetColor(0); ofFill();
	for (unsigned int i = 0; i < grid.size(); i++) {
		ofDrawCircle(grid[i], 1);
	}
	for (unsigned int i = 0; i < CELLS.size(); i++) {
		CELLS[i].draw();
	}

	for (int i = 0; i < agentVec.size(); i++) {	
		for (int j = 0; j < agentVec[i].cellsOccupied.size(); j++) {
			Cell cell = agentVec[i].cellsOccupied[j];			
			cell.display(COLOR[i]);
			ofSetColor(0);
			//string s = to_string(cell.cellId) + ", " + to_string(i);
			string s = to_string(i);
			ofDrawBitmapString(s, cell.X + 5, cell.Y + cell.W / 3);
		}
	}
	/*
	ofDrawBitmapStringHighlight(MSG, 10, ofGetHeight() - 50);
	*/
}

void ofApp::keyPressed(int key){
	if (key == 'a' || key == 'A') init();
}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::mouseEntered(int x, int y){

}

void ofApp::mouseExited(int x, int y){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
