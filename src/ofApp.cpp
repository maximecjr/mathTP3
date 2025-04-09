#include "ofApp.h"
#include <iostream>
void runTests() {
    std::cout << "== DEBUT DES TESTS ==" << std::endl;

    // Test 1 : Création d'un mur
    Wall w(ofVec3f(0, 0, 0), ofVec3f(100, 100, 0));
    std::cout << "Mur cree de (0,0) a (100,100)." << std::endl;

    // Test 2 : Création d'une particule
    Particle p(ofVec2f(50, 50));
    std::cout << "Particule creee a (50,50)." << std::endl;

    // Test 3 : Déplacement de la particule
    p.update(200, 200);
    std::cout << "Particule deplacee a (200,200)." << std::endl;

    // Test 4 : Nombre de rayons (facultatif, selon ton implémentation)
    if (p.rays.size() > 0) {
        std::cout << "OK : " << p.rays.size() << " rayons generes." << std::endl;
    } else {
        std::cout << "ERREUR : Aucun rayon genere." << std::endl;
    }
    std::cout << "== FIN DES TESTS ==" << std::endl;

}
//--------------------------------------------------------------
void ofApp::setup()
{
    runTests();
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
    
}


//FONCTION EXEMPLE INUTILISE DANS NOTRE PROJET

//--------------------------------------------------------------
void ofApp::exit()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
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
