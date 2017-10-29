#include "HoverCar.h"

Sphere HoverCar::getColisionFrontSphere()
{
	colisionFrontSphere.setPositon(vec2(colisionFront->getModel()->GetX(), colisionFront->getModel()->GetZ()));
	return colisionFrontSphere;
}

Sphere HoverCar::getColisionBackSphere()
{
	colisionBackSphere.setPositon(vec2(colisionBack->getModel()->GetX(), colisionBack->getModel()->GetZ()));
	return colisionBackSphere;
}

Entity* HoverCar::getMomentumEntity()
{
	return momentumEntity;
}

Entity* HoverCar::getThirdPersonCameraMovmentEntity()
{
	return thirdPersonCameraMovmentEntity;
}

Entity* HoverCar::getThirdPersonCameraRotationEntity()
{
	return thirdPersonCameraRotationEntity;
}