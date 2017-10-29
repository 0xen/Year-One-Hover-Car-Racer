#include "Sphere.h"


Sphere::Sphere()
{
	rad = 0.0f;
}

void Sphere::setPositon(vec2 _pos)
{
	position = _pos;
}

void Sphere::setRadius(float _rad)
{
	rad = _rad;
}

vec2 Sphere::getPosition()
{
	return position;
}

float Sphere::getRadius()
{
	return rad;
}