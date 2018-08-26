#include "ofApp.h"

void ofApp::init() {
	agent.clear();
	int t = (int)ofRandom(0, grid.size() - 1);
	agent.setInCell(cells[t]);
	agent.addAllCells(cells);
}


void ofApp::moveAgent() {
	agent.move();
}

void ofApp::resetGrids() {
	gridLength = gui->gridLength; gridWidth = gui->gridWidth; agentArea = gui->agentArea;
	prevL = gridLength; prevW = gridWidth;
	grid.clear(); cells.clear(); int k = 0; int posx = 0; int posy = 0;
	for (unsigned int i = 0; i < ofGetWidth(); i += gridLength) {
		for (unsigned int j = 0; j < ofGetWidth(); j += gridWidth) {
			grid.push_back(ofVec3f(i, j, 0));
			cells.push_back(Cell(k, i, j, gridLength, gridWidth, posx, posy));
			posy++; k++;
		}
		posx++;
	}
	agent.clear();
}

void ofApp::setup(){
	gridLength = 50;
	gridWidth = 50;
	prevL = gridLength;
	prevW = gridWidth;
	int k = 0;; int posx=0; int posy=0;
	for (unsigned int i = 0; i < ofGetWidth(); i+=gridLength) {
		for (unsigned int j = 0; j < ofGetWidth(); j+=gridWidth) {
			grid.push_back(ofVec3f(i, j, 0));
			cells.push_back(Cell(k, i, j, gridLength, gridWidth, posx, posy));
			posy++; k++;
		}
		posx++;
	}
}

void ofApp::update(){
	gridLength = gui->gridLength; gridWidth = gui->gridWidth;
	if (prevL != gridLength || prevW != gridWidth) {
		resetGrids();
	}
}

void ofApp::draw(){
	ofBackground(255); ofSetColor(0); ofFill();
	for (unsigned int i = 0; i < grid.size(); i++) {
		ofDrawCircle(grid[i], 1);
	}
	for (unsigned int i = 0; i < cells.size(); i++) {
		cells[i].draw();
	}
	
	for (unsigned int i = 0; i < agent.cellOccupied.size(); i++) {
		agent.cellOccupied[i].display();
	}
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
