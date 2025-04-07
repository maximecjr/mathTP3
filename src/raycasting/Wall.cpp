#include "Wall.h"

Wall::Wall(const ofVec3f &pos1, const ofVec3f &pos2)
{
    this->pos1 = pos1;
    this->pos2 = pos2;
}

void Wall::show()
{
    ofDrawLine(pos1.x,pos1.y,pos2.x,pos2.y);
}
