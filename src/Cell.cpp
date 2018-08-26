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

void Cell::display() {
	ofSetColor(255, 0, 0, 150);
	ofFill(); 
	ofDrawRectangle(X, Y, L, W);	
	ofSetColor(0); ofFill();
	ofDrawBitmapString(cellId, X + 5, Y + W / 3);
}

ofVec3f Cell::cellMP() {
	ofVec3f p(X + (L / 2), Y + (W / 2), 0);
	return p;
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