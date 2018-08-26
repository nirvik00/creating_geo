#include "ofApp.h"

void ofApp::init() {

	cout << "\n\n\n";
	agent.clear();
	int t = 0;
	ofVec3f p((ofGetWidth() / 2), (ofGetHeight() / 2));
	for (int i = 0; i < CELLS.size(); i++) {
		if (CELLS[i].contains(p)) {
			t = i; break;
		}
	}
	agent.setInCell(CELLS[t]);
	agent.addAllCells(CELLS);
	agent.setArea(gui->agentArea);
	agent.initMove();

	float sum = 0; 
	for (int i = 0; i < agent.cellsOccupied.size(); i++) {
		Cell cell = agent.cellsOccupied[i];
		sum += cell.getArea();
	}
	cout << "\n\n(end of run) total=" << sum << endl;
}


void ofApp::moveAgent() {
	agent.move(0);
	
}

void ofApp::resetGrids() {
	gridLength = gui->gridLength; 
	gridWidth = gui->gridWidth; 
	agentArea = gui->agentArea;

	prevL = gridLength; prevW = gridWidth;
	
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
	agent.clear();
}

void ofApp::setup(){
	gridLength = 50;
	gridWidth = 50;
	prevL = gridLength;
	prevW = gridWidth;
	indX = 0;
	indY = 0;
	resetGrids();
}

void ofApp::update(){
	gridLength = gui->gridLength; gridWidth = gui->gridWidth;
	if (prevL != gridLength || prevW != gridWidth) {
		resetGrids();
	}

	float sum = 0;
	string S = "...";
	for (int i = 0; i < agent.cellsOccupied.size(); i++) {
		Cell cell = agent.cellsOccupied[i];
		//S += ","+to_string(cell.getArea());
		sum += cell.getArea();
	}
	MSG = "Required area of cells = " + to_string(gui->agentArea);
	MSG += "\nAchieved Area of cells = " + to_string(sum) + S;
	
}

void ofApp::draw(){
	ofBackground(255); ofSetColor(0); ofFill();
	for (unsigned int i = 0; i < grid.size(); i++) {
		ofDrawCircle(grid[i], 1);
	}
	for (unsigned int i = 0; i < CELLS.size(); i++) {
		CELLS[i].draw();
	}
	
	for (unsigned int i = 0; i < agent.cellsOccupied.size(); i++) {
		agent.cellsOccupied[i].display();
	}

	ofSetColor(0); ofFill();
	ofDrawBitmapStringHighlight(MSG, 10, ofGetHeight() - 50);
}

void ofApp::keyPressed(int key){
	if (key == 'a' || key == 'A') init();
	if (key == 'm' || key == 'M') moveAgent();
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
