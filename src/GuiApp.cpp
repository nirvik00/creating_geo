#include "GuiApp.h"

void GuiApp::setup()
{
	parameters.setName("Controls");
	parameters.add(gridLength.set("Grid Length", 50, 25, 100));
	parameters.add(gridWidth.set("Grid Width", 50, 25, 100));

	parameters.add(agentArea1.set("Area 0", 2500, 2500, 50000));
	parameters.add(agentArea2.set("Area 1", 2500, 2500, 50000));
	parameters.add(agentArea3.set("Area 2", 2500, 2500, 50000));
	parameters.add(agentArea4.set("Area 3", 2500, 2500, 50000));
	parameters.add(agentArea5.set("Area 4", 2500, 2500, 50000));

	
	parameters.add(color0.set("color Area 0", 100, ofColor(0, 0), 255));
	parameters.add(color1.set("color Area 1", 100, ofColor(0, 0), 255));
	parameters.add(color2.set("color Area 2", 100, ofColor(0, 0), 255));
	parameters.add(color3.set("color Area 3", 100, ofColor(0, 0), 255));
	parameters.add(color4.set("color Area 4", 100, ofColor(0, 0), 255));


	gui.setup(parameters);
	ofBackground(255);
	ofSetVerticalSync(false);
}


void GuiApp::update() {

}


void GuiApp::draw() {
	ofSetBackgroundColor(255);
	gui.draw();
	ofDrawBitmapStringHighlight("KEYBOARD CONTROLS", 10, 600);
	ofDrawBitmapStringHighlight("Press a / A to generate geometry", 10, 620);
}
