#include "Ray.h"

// Initialize the Ray with an origin and direction
Ray::Ray(const ofVec3f &origin, const ofVec3f &direction)
{
    this->origin = origin;
    // Normalize the direction to avoid scaling issues
    this->direction = direction.getNormalized();
}

// Intersect this Ray with a plane defined by planeNormal·p = d
bool Ray::intersectPlane(ofVec3f &planeNormal, float d)
{
    return true;
}

// Visualize the ray in 3D
// By default, draw the ray out to some 'length' for debugging
void Ray::draw()
{
    ofDrawLine(this->origin, this->origin + this->direction * 1000);
}

void Ray::cast(std::vector<Wall> &walls)
{
}
