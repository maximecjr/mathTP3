#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main() {

	// Lancer les tests avant de commencer l'application principale
	std::cout << "Lancement des tests..." << std::endl;
	// Une fois les tests passés, lancer l'application OpenFrameworks
	ofGLWindowSettings settings;
	settings.setSize(1024, 768);
	settings.windowMode = OF_WINDOW;

	auto window = ofCreateWindow(settings);
	ofRunApp(window, make_shared<ofApp>());
	ofRunMainLoop();

	return 0;
}
