#pragma once

#include "Entity.h"
#include "Cube.h"
#include "ConstVarables.h"

class Wall
{
public:
	Wall(vec3 posiiton);
	vector<Cube*> getHitboxes();
private:
	Entity* wall;
	Entity* isleStright1;
	Entity* isleStright2;
	vector<Cube*> hitBoxes;
};