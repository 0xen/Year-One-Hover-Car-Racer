#include "Cube.h"

Cube::Cube(float _x, float _z)
{
	x = _x;
	z = _z;
}

void Cube::setPosiiton(vec2 _pos)
{
	pos = _pos;
}

void Cube::setXRad(float _x)
{
	x = _x;
}

void Cube::setZRad(float _z)
{
	z = _z;
}

vec2 Cube::getPosition()
{
	return pos;
}

float Cube::getXRad()
{
	return x;
}

float Cube::getZRad()
{
	return z;
}