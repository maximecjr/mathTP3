#include "Ray.h"

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

void Ray::cast(std::vector<Wall> &walls)
{
    ofVec3f closestPoint;
    float minDist = std::numeric_limits<float>::infinity();
    bool foundIntersection = false;

    for (auto &wall : walls)
    {
        // Paramétrisation du segment (mur)
        ofVec3f a = wall.pos1;
        ofVec3f b = wall.pos2;

        // Vecteurs utiles
        ofVec3f wallDir = b - a;
        ofVec3f rayToWall = a - origin;

        float det = direction.x * (-wallDir.y) + direction.y * wallDir.x;

        // Si le déterminant est proche de 0, les droites sont parallèles
        if (abs(det) < 1e-6)
            continue;

        // Calcul de t (paramètre du rayon) et u (paramètre du segment)
        float t = (rayToWall.x * (-wallDir.y) + rayToWall.y * wallDir.x) / det;
        float u = (direction.x * rayToWall.y - direction.y * rayToWall.x) / det;

        // Test si l'intersection est sur le segment et devant le rayon
        if (t > 0 && u >= 0 && u <= 1)
        {
            ofVec3f intersection = origin + direction * t;
            float dist = (intersection - origin).length();
            if (dist < minDist)
            {
                minDist = dist;
                closestPoint = intersection;
                foundIntersection = true;
            }
        }
    }

    if (foundIntersection)
    {
        // Affiche le rayon jusqu’au point d’intersection
        ofDrawLine(origin, closestPoint);
    }
    else
    {
        // Aucun mur touché, le rayon va loin
        ofDrawLine(origin, origin + direction * 1000);
    }
}

