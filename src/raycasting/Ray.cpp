#include "Ray.h"
#include "ofApp.h"
// Initialize the Ray with an origin and direction
//gére les rayons qui representeront la vision des personnages
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
//reprends le principe du draw mais y ajoute le test d'intersection afin de s'arreter en cas de collision
void Ray::cast(std::vector<Wall> &walls, bool reflectRays)
{
    float closestDist = std::numeric_limits<float>::max();
    ofVec3f closestPoint;
    bool hitWall = false;
    ofVec3f reflectionDir;

    for (auto &wall : walls)
    {
        ofVec3f p1 = wall.pos1;
        ofVec3f p2 = wall.pos2;
        ofVec3f dir = this->direction;
        ofVec3f orig = this->origin;

        ofVec3f wallDir = p2 - p1;
        ofVec3f diff = p1 - orig;

        float denom = dir.x * wallDir.y - dir.y * wallDir.x;
        if (abs(denom) < 1e-6) continue;

        float t = (diff.x * wallDir.y - diff.y * wallDir.x) / denom;
        float u = (diff.x * dir.y - diff.y * dir.x) / denom;

        if (t > 0 && u >= 0 && u <= 1)
        {
            ofVec3f pt = orig + dir * t;
            float dist = (pt - orig).length();

            if (dist < closestDist)
            {
                closestDist = dist;
                closestPoint = pt;
                hitWall = true;

                ofVec3f normal = ofVec3f(-wallDir.y, wallDir.x, 0);
                normal.normalize();

                if (reflectRays) {
                    reflectionDir = dir - 2 * (dir.dot(normal)) * normal;
                }
            }
        }
    }

    if (hitWall)
    {
        ofDrawLine(origin, closestPoint);

        if (reflectRays)
        {
            // Lancer un rayon réfléchi à partir de closestPoint
            float reflectedClosestDist = std::numeric_limits<float>::max();
            ofVec3f reflectedHitPoint;
            bool reflectedHit = false;

            for (auto &wall : walls)
            {
                ofVec3f p1 = wall.pos1;
                ofVec3f p2 = wall.pos2;
                ofVec3f dir = reflectionDir;
                ofVec3f orig = closestPoint;

                ofVec3f wallDir = p2 - p1;
                ofVec3f diff = p1 - orig;

                float denom = dir.x * wallDir.y - dir.y * wallDir.x;
                if (abs(denom) < 1e-6) continue;

                float t = (diff.x * wallDir.y - diff.y * wallDir.x) / denom;
                float u = (diff.x * dir.y - diff.y * dir.x) / denom;

                if (t > 0.001 && u >= 0 && u <= 1)  // t > 0.001 pour éviter collision immédiate avec le mur d’origine
                {
                    ofVec3f pt = orig + dir * t;
                    float dist = (pt - orig).length();

                    if (dist < reflectedClosestDist)
                    {
                        reflectedClosestDist = dist;
                        reflectedHitPoint = pt;
                        reflectedHit = true;
                    }
                }
            }

            if (reflectedHit)
            {
                ofDrawLine(closestPoint, reflectedHitPoint);
            }
            else
            {
                ofDrawLine(closestPoint, closestPoint + reflectionDir * 1000);
            }
        }
    }
    else
    {
        ofDrawLine(origin, origin + direction * 1000);
    }
}
