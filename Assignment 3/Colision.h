#pragma once

#include "Sphere.h"
#include "Cube.h"
#include <iostream>
namespace Colision
{
	bool sphereToPoint(Sphere sphere, vec2 pointPos);
	bool sphereToPoint(vec2 spherePos, float sphereWidth, vec2 pointPos);
	bool sphereToSphere(Sphere sphere1, Sphere sphere2);
	bool sphereToSphere(vec2 sphere1Pos, float sphere1Width, vec2 sphere2Pos, float sphere2Width);
	bool pointToCube(vec2 point, Cube cube);
	bool sphereToCube(Sphere sphere, Cube cube);
}