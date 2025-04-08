
#include "Particle.h"
//dessine le personnage et les rayons qui represente sa vision.
Particle::Particle(ofVec2f pos)
{
    this->pos = pos;

    // Create rays in a circle (0° to 350° in 10° increments)
    for (int i = 0; i < 360; i += 10)
    {
        float rad = ofDegToRad(i);
        // Compute 2D direction in the XY plane; z is 0.
        ofVec3f direction(cos(rad), sin(rad), 0);
        // rays.push_back(RayPlan(this->pos, direction));
        rays.push_back(Ray(this->pos, direction));
    }
}

void Particle::update(float x, float y)
{
    this->pos.set(x, y);
}

void Particle::show(std::vector<Wall> &walls)
{
    ofDrawCircle(this->pos, 5);

    for (auto &ray : rays)
    {
        ray.origin = this->pos;
        ray.cast(walls);
    }
}
