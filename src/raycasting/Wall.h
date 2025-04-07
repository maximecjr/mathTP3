#pragma once
#include "ofMain.h"

class Wall
{
public:
    ofVec3f pos1, pos2; // Endpoints of the wall segment in 3D space
    ofVec3f normal;     // Normal vector for the plane defined by the wall (lies in the XY plane)
    float d;            // Scalar for the plane equation: n · p = d
    // Constructor that accepts 3D points
    Wall(const ofVec3f &pos1, const ofVec3f &pos2);

    // Method to draw the wall
    void show();
};
