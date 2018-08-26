#include "GuiApp.h"

void GuiApp::setup()
{
	parameters.setName("Controls");
	parameters.add(gridLength.set("Grid Length", 50, 5, 100));
	parameters.add(gridWidth.set("Grid Width", 50, 5, 100));
	parameters.add(agentArea.set("Agent Area", 500, 5, 10000));
	gui.setup(parameters);
	ofBackground(255);
	ofSetVerticalSync(false);
}


void GuiApp::update() {

}


void GuiApp::draw() {
	ofSetBackgroundColor(255);
	gui.draw();
	ofDrawBitmapStringHighlight("Press a / A to initialize agent", 10, 200);
}
