#pragma once

#include "Vec.h"

class Cube
{
public:
	Cube(float _x, float _z);
	void setPosiiton(vec2 _pos);
	void setXRad(float _x);
	void setZRad(float _z);
	vec2 getPosition();
	float getXRad();
	float getZRad();
private:
	vec2 pos;
	float x;
	float z;
};