#pragma once

#include <TL-Engine.h>
#include <iostream>
#include <unordered_map>
using namespace tle;

#include "Vec.h"

class Entity
{
public:
	Entity(std::string _meshFileLocation, float _x, float _y, float _z);
	Entity(std::string _meshFileLocation, vec3 vec);
	IModel* getModel();
	void move(vec3 movment);
	static void passEngineRefrence(I3DEngine*& _myEngine);

private:
	std::string meshFileLocation;
	IModel* entityModel;
	void createModel(float x, float y, float z);
};