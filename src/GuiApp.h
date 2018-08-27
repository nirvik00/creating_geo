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
	
	ofParameter<float> agentArea1;
	ofParameter<float> agentArea2;
	ofParameter<float> agentArea3;
	ofParameter<float> agentArea4;
	ofParameter<float> agentArea5;

	ofParameter<ofColor> color0;
	ofParameter<ofColor> color1;
	ofParameter<ofColor> color2;
	ofParameter<ofColor> color3;
	ofParameter<ofColor> color4;

	ofxPanel gui;

};