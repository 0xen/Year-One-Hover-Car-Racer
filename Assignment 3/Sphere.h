#pragma once

#include "Vec.h"

class Sphere
{
public:
	Sphere();
	void setPositon(vec2 _pos);
	void setRadius(float _rad);
	vec2 getPosition();
	float getRadius();
private:
	vec2 position;
	float rad;
};