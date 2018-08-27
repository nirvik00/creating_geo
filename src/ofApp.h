#pragma once

#include "ofMain.h"
#include "GuiApp.h"

#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>

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
	Agent agentProc(Agent, int);
	void resetSystem();
	ofColor colorScheme(int);
	void colorScheme();
	int findAppropriateCellIndex();

	/**/
	shared_ptr<GuiApp> gui;

	/**/
	float prevL, prevW;
	float gridLength, gridWidth;
	int indX, indY;
	string MSG="";

	vector<ofVec3f> grid;
	vector<Cell> CELLS;
	vector<Cell> procOccupiedCells;

	const int NUM = 5;
	float agentAreaArr[5];
	vector<Agent> agentVec;

	ofColor COLOR1, COLOR2, COLOR3, COLOR4, COLOR5;	
	ofColor COLOR[5];

};