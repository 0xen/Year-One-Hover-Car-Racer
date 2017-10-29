#include "Colision.h"


bool Colision::sphereToPoint(Sphere sphere, vec2 pointPos)
{
	return sphereToPoint(sphere.getPosition(), sphere.getRadius(), pointPos);
}

bool Colision::sphereToPoint(vec2 spherePos, float sphereWidth, vec2 pointPos)
{
	return spherePos.distanceBetween(pointPos) - sphereWidth < 0.0f;
}

bool Colision::sphereToSphere(Sphere sphere1, Sphere sphere2)
{
	return sphereToSphere(sphere1.getPosition(), sphere1.getRadius(), sphere2.getPosition(), sphere2.getRadius());
}

bool Colision::sphereToSphere(vec2 sphere1Pos, float sphere1Width, vec2 sphere2Pos, float sphere2Width)
{
	return sphere1Pos.distanceBetween(sphere2Pos) - sphere1Width - sphere2Width < 0.0f;
}

bool Colision::pointToCube(vec2 point, Cube cube)
{
	if (
		cube.getPosition().x - cube.getXRad() < point.x&&
		cube.getPosition().x + cube.getXRad() > point.x&&
		cube.getPosition().z - cube.getZRad() < point.z&&
		cube.getPosition().z + cube.getZRad() > point.z
		)
	{
		return true;
	}
	return false;

}

bool Colision::sphereToCube(Sphere sphere, Cube cube)
{
	cube.setXRad(cube.getXRad() + sphere.getRadius());
	cube.setZRad(cube.getZRad() + sphere.getRadius());
	return pointToCube(sphere.getPosition(), cube);
}