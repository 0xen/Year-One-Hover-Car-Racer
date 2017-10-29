#include "Wall.h"

Wall::Wall(vec3 position)
{

	wall = new Entity(ConstVars::kWallLocation, position);
	isleStright1 = new Entity(ConstVars::kIsleStraightLocation, vec3(0.5f, 0.0f, -6.0f));
	isleStright1->getModel()->AttachToParent(wall->getModel());
	isleStright2 = new Entity(ConstVars::kIsleStraightLocation, vec3(0.5f, 0.0f, 5.0f));
	isleStright2->getModel()->AttachToParent(wall->getModel());

	std::cout << wall->getModel()->GetX() << " " << wall->getModel()->GetZ() << std::endl;
	std::cout << isleStright1->getModel()->GetX() << " " << isleStright1->getModel()->GetZ() << std::endl;
	std::cout << isleStright2->getModel()->GetX() << " " << isleStright2->getModel()->GetZ() << std::endl;

	Cube* wallColision = new Cube(0.934082f, 4.83559f);
	Cube* isleStright1Colision = new Cube(2.67529f, 3.41748f);
	Cube* isleStright2Colision = new Cube(2.67529f, 3.41748f);

	wallColision->setPosiiton(vec2(wall->getModel()->GetX(), wall->getModel()->GetZ()));
	isleStright1Colision->setPosiiton(vec2(isleStright1->getModel()->GetX(), isleStright1->getModel()->GetZ()));
	isleStright2Colision->setPosiiton(vec2(isleStright2->getModel()->GetX(), isleStright2->getModel()->GetZ()));
	hitBoxes.push_back(wallColision);
	hitBoxes.push_back(isleStright1Colision);
	hitBoxes.push_back(isleStright2Colision);
}


vector<Cube*> Wall::getHitboxes()
{
	return hitBoxes;
}