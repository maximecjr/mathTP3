#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(0); // Fond noir
    //crée le personnage
    particle = Particle(ofVec2f(100, 100));
    //crée les murs de maniére aléatoire
    for (int i = 0; i < 20; i++) {
        ofVec3f start(ofRandom(0, 1024), ofRandom(0, 768), 100);
        ofVec3f end = start + ofVec3f(ofRandom(-100, 250), ofRandom(-100, 250), 0);
        walls.push_back(Wall(start, end));
    }
}


    bool reflectRays = false;  // Variable pour gérer l'état de réflexion des rayons

//--------------------------------------------------------------
//gere le deplacement du personnage (souris)
void ofApp::update()
{
    particle.update(ofGetMouseX(), ofGetMouseY());
}

//--------------------------------------------------------------
void ofApp::draw()
{
    //appel la fonction pour dessiner les rayons et les murs.
    particle.show(walls);
    for (int i = 0; i < walls.size(); i++)
    {
        walls.at(i).show();
    }
    // Afficher le texte "Press E to reflect rays" en rouge
    if (!reflectRays) {
        ofDrawBitmapString("Press E to reflect rays", 20, 20);
    } else {
        ofDrawBitmapString("Reflection enabled", 20, 20);  // Afficher un autre texte quand la réflexion est activée
    }

    for (auto &ray : particle.rays)
    {
        ray.cast(walls, reflectRays);  
    }
}


//FONCTION EXEMPLE INUTILISE DANS NOTRE PROJET

//--------------------------------------------------------------
void ofApp::exit()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 'e' || key == 'E')  // Si la touche E est pressée
    {
        reflectRays = !reflectRays;  // Alterne l'état (réfléchir ou non)
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
