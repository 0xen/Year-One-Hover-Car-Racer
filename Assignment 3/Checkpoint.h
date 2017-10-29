#pragma once

#include "Entity.h"
#include "ConstVarables.h"
#include "Sphere.h"

class Checkpoint : public Entity
{
public:
	Checkpoint(vec3 vec, int _checkpointID) : Entity(ConstVars::kCheckpointLocation, vec)
	{
		float colisionRad = 5.0f;
		checkpointID = _checkpointID;
		checkpointEntity = new Entity(ConstVars::kSphereLocation, vec3(0.0f, 0.0f, 0.0f));
		checkpointEntity->getModel()->Scale(((1.0f / ConstVars::kSphereWidth) * colisionRad) * 2.0f);
		checkpointEntity->getModel()->AttachToParent(getModel());

		checkpointSphere.setPositon(vec2(vec.x, vec.z));
		checkpointSphere.setRadius(colisionRad);
	}
	Sphere checkpointSphere;
private:
	int checkpointID;
	Entity* checkpointEntity;
};