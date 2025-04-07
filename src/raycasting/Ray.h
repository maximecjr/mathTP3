#pragma once
#include "ofMain.h"
#include "Wall.h"

class Ray
{
public:
    ofVec3f origin;    // Ray origin
    ofVec3f direction; // Ray direction (should be normalized)
    ofVec3f intersectionPoint;

    Ray(const ofVec3f &origin, const ofVec3f &direction);

    bool intersectPlane(ofVec3f &planeNormal, float d);

    void cast(std::vector<Wall> &walls);

    // For visual debugging
    void draw();
};
