#pragma once

#include "ofMain.h"
#include "GuiApp.h"

#include <vector>


#include "Cell.h"
#include "Agent.h"

class ofApp : public ofBaseApp 
{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	/*	MY METHODS	*/
	void init();
	void moveAgent();
	void resetGrids();
		
	/**/
	shared_ptr<GuiApp> gui;

	/**/
	float prevL, prevW;
	float gridLength, gridWidth;
	int indX, indY;
	string MSG="";

	float agentArea;

	vector<ofVec3f> grid;
	vector<Cell> CELLS;
	vector<Cell> occupiedCells;

	Agent agent;

};