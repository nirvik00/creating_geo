#pragma once


#include "ofMain.h"
#include "ofxGui.h";

class GuiApp : public ofBaseApp 
{
public:
	void setup();
	void update();
	void draw();
	
	ofParameterGroup parameters;
	ofParameter<float> gridLength;
	ofParameter<float> gridWidth;
	
	ofParameter<float> agentArea;

	ofxPanel gui;

};