#pragma once
#include "ofMain.h"
#include "Wall.h"
#include "Ray.h"

class Particle
{
public:
    Particle(ofVec2f pos = ofVec2f(100, 100));

public:
    ofVec2f pos;

    std::vector<Ray> rays;

public:
    void update(float x, float y);
    void show(std::vector<Wall> &walls);
};
