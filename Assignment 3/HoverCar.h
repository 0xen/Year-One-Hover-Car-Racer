#pragma once
#include "Entity.h"
#include "ConstVarables.h"
#include "Sphere.h"

class HoverCar : public Entity
{
public:
	HoverCar(vec3 posiiton) : Entity(ConstVars::kHoverCarLocation, vec3())
	{
		float colisionRad = 2.5f;
		//Front colision
		colisionFront = new Entity(ConstVars::kSphereLocation, vec3(0.0f, 0.0f, 4.0f));
		colisionFront->getModel()->Scale(((1.0f / ConstVars::kSphereWidth) * colisionRad) * 2);
		colisionFront->getModel()->AttachToParent(getModel());
		//back colision
		colisionBack = new Entity(ConstVars::kSphereLocation, vec3(0.0f, 0.0f, -4.0f));
		colisionBack->getModel()->Scale(((1.0f / ConstVars::kSphereWidth) * colisionRad) * 2);
		colisionBack->getModel()->AttachToParent(getModel());



		momentumEntity = new Entity(ConstVars::kDummyLocation, posiiton);
		getModel()->AttachToParent(momentumEntity->getModel());
		thirdPersonCameraMovmentEntity = new Entity(ConstVars::kDummyLocation, vec3());
		thirdPersonCameraMovmentEntity->getModel()->AttachToParent(momentumEntity->getModel());
		thirdPersonCameraRotationEntity = new Entity(ConstVars::kDummyLocation, vec3());
		thirdPersonCameraRotationEntity->getModel()->AttachToParent(thirdPersonCameraMovmentEntity->getModel());

		colisionFrontSphere.setPositon(vec2(posiiton.x, posiiton.z));
		colisionFrontSphere.setRadius(colisionRad);
		colisionBackSphere.setPositon(vec2(posiiton.x, posiiton.z));
		colisionBackSphere.setRadius(colisionRad);
	}
	Sphere getColisionFrontSphere();
	Sphere getColisionBackSphere();
	Entity* getMomentumEntity();
	Entity* getThirdPersonCameraMovmentEntity();
	Entity* getThirdPersonCameraRotationEntity();
private:
	Entity* momentumEntity;
	Entity* thirdPersonCameraRotationEntity;
	Entity* thirdPersonCameraMovmentEntity;
	Entity* colisionFront;
	Entity* colisionBack;
	Sphere colisionFrontSphere;
	Sphere colisionBackSphere;
};