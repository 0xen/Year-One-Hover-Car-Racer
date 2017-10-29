#include "Entity.h"

static I3DEngine* myEngine;
static unordered_map<std::string, IMesh*> meshPointers;


Entity::Entity(std::string _meshFileLocation, float _x, float _y, float _z)
{
	meshFileLocation = _meshFileLocation;
	createModel(_x, _y, _z);
}

Entity::Entity(std::string _meshFileLocation, vec3 vec)
{
	meshFileLocation = _meshFileLocation;
	createModel(vec.x, vec.y, vec.z);
}

IModel* Entity::getModel()
{
	return entityModel;
}
void Entity::move(vec3 movment)
{
	entityModel->Move(movment.x, movment.y, movment.z);
}

void Entity::passEngineRefrence(I3DEngine*& _myEngine)
{
	myEngine = _myEngine;
}
void Entity::createModel(float x, float y, float z)
{
	IMesh* entityMesh;
	std::unordered_map<std::string, IMesh*>::iterator it = meshPointers.find(meshFileLocation);
	if (it != meshPointers.end())
	{
		entityMesh = meshPointers[meshFileLocation];
	}
	else
	{
		std::cout << "Loading new mesh: " << meshFileLocation.c_str() << std::endl;
		entityMesh = myEngine->LoadMesh(meshFileLocation);
		meshPointers[meshFileLocation] = entityMesh;
	}
	entityModel = entityMesh->CreateModel(x, y, z);
}