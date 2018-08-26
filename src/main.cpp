#include "ofMain.h"
#include "ofAppGLFWWindow.h"

#include "ofApp.h"
#include "GuiApp.h"

#include "Cell.h"
#include "Agent.h"

int main( ){
	ofGLFWWindowSettings settings;

	//gui window
	settings.setSize(300, 1000);
	settings.setPosition(ofVec2f(0, 0));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);

	//ofApp window
	settings.setSize(1000, 1000);
	settings.setPosition(ofVec2f(300,0));
	settings.resizable = true;
	shared_ptr<ofAppBaseWindow> viewWindow = ofCreateWindow(settings);

	shared_ptr<GuiApp>guiApp(new GuiApp); //GuiApp
	shared_ptr<ofApp>viewApp(new ofApp); //ofApp
	
	viewApp->gui = guiApp;

	ofRunApp(viewWindow, viewApp);
	ofRunApp(guiWindow, guiApp);

	ofRunMainLoop();

}
