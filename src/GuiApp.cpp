#include "GuiApp.h"

void GuiApp::setup()
{
	parameters.setName("Controls");
	parameters.add(gridLength.set("Grid Length", 50, 50, 100));
	parameters.add(gridWidth.set("Grid Width", 50, 50, 100));
	parameters.add(agentArea.set("Agent Area", 2500, 2500, 100000));
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
	ofDrawBitmapStringHighlight("Press n / N for next generation", 10, 250);
}
