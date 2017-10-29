#include "Vec.h"

vec3::vec3()
{
	// Sets x,y, and z to 0 as the user has not given us a default value
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}

vec3::vec3(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

float vec3::length()
{
	return sqrt(x*x + y * y + z*z);
}

float vec3::distanceBetween(vec3& vec)
{
	float xa = x - vec.x, ya = y - vec.y, za = z - vec.z;
	return sqrt(xa*xa + ya*ya + za*za);
}

vec2::vec2()
{
	// Sets x and z to 0 as the user has not given us a default value
	x = 0.0f;
	z = 0.0f;
}

vec2::vec2(float _x, float _z)
{
	x = _x;
	z = _z;
}

float vec2::length()
{
	return sqrt(x*x + z*z);
}

float vec2::distanceBetween(vec2& vec)
{
	float xa = x - vec.x, za = z - vec.z;
	return sqrt(xa*xa + za*za);
}

vec2 vec2::scalar(float scale, vec2 vec)
{
	return vec2(scale*vec.x, scale*vec.z);
}
vec2 vec2::sum(vec2 v1, vec2 v2, vec2 v3)
{
	return vec2(v1.x + v2.x + v3.x, v1.z + v2.z + v3.z);
}