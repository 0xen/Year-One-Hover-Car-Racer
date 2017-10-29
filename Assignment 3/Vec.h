#pragma once
#include <math.h>
class vec3
{
public:
	float x, y, z;
	vec3();
	vec3(float _x, float _y, float _z);
	float length();
	float distanceBetween(vec3& vec);
};

class vec2
{
public:
	float x, z;
	vec2();
	vec2(float _x, float _z);
	float length();
	float distanceBetween(vec2& vec);
	vec2 vec2::operator+(const vec2& vec)
	{
		return vec2(this->x + vec.x, this->z + vec.z);
	}
	static vec2 scalar(float scale, vec2 vec);
	static vec2 sum(vec2 v1, vec2 v2, vec2 v3);
};