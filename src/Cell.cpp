#include "Cell.h"

Cell::Cell(int id, float x, float y, float l, float w, int i, int j) { 
	cellId = (int)id; 
	X = x; Y = y; L = l; W = w;
	indX = i; indY = j;
	occupied = 0;
}

void Cell::draw() {
	ofNoFill(); ofSetLineWidth(1);
	ofSetColor(200, 200, 200); ofDrawRectangle(X, Y, L, W); // fill boundary
}

void Cell::display(ofColor co) {
	/* 
	* color comes from ofApp::draw COLOR=gui->color 
	*/
	ofSetColor(co); ofFill();
	ofDrawRectangle(X, Y, L, W);
}

ofVec3f Cell::cellMP() {
	ofVec3f p(X + (L / 2), Y + (W / 2), 0);
	return p;
}

float Cell::di(Cell r) {
	ofVec3f a= cellMP();
	ofVec3f b = r.cellMP();
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));
}


bool Cell::contains(ofVec3f p) {
	bool t = false;
	if (p.x > X && p.x < X + L) {
		if (p.y > Y && p.y < Y + W) {
			t = true;
		}
	}
	if(p.x==X && p.y==Y){
		t = true;
	}
	return t;
}

void Cell::setOccupied(int t) {
	occupied = t;
}

int Cell::getOccupied() {
	return occupied;
}