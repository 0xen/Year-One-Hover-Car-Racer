
#include <TL-Engine.h>
#include <iostream>
#include <windows.h>

#include "ConstVarables.h"
#include "Entity.h"
#include "HoverCar.h"
#include "Checkpoint.h"
#include "Colision.h"
#include "Wall.h"

using namespace tle;

enum GameStates { PreGame, CheckeredFlagCountdown, Playing };

I3DEngine* myEngine;

GameStates gameState = GameStates::PreGame;
IFont* font;
HoverCar* hoverCar;

vector<Checkpoint*> checkpoints;
vector<Wall*> walls;

float deltaTime = ConstVars::kFrameTime;
float gameTimeRaw = 0.0f;
int checkPointState = 1;
int seccondsPassed = 0;
int fps = 0;
int dfps = 0;

vec2 momentum;
vec2 thrust;
vec2 drag;
float matrix[4][4];

void preRender()
{
	while (deltaTime > 0.0f)
	{
		Sleep(1);
		float lastCheckTime = myEngine->Timer();
		deltaTime -= lastCheckTime;
		gameTimeRaw += lastCheckTime;
	}
	dfps++;
	if (seccondsPassed != floor(gameTimeRaw))
	{
		seccondsPassed = (int) floor(gameTimeRaw);
		fps = dfps;
		dfps = 0;
		std::cout << "FPS:" << fps << std::endl;
	}
}

void postRender()
{
	float lastCheckTime = myEngine->Timer();
	gameTimeRaw += lastCheckTime;
	deltaTime = ConstVars::kFrameTime - lastCheckTime;
}

void resetTime()
{
	seccondsPassed = 0;
	deltaTime = 0.0f;
	gameTimeRaw = -3.0f;
	myEngine->Timer();
}

void drawDialougeMessage(const char* message, int row)
{
	int x = ConstVars::kTextDisplayAreas[row].x;
	int y = ConstVars::kTextDisplayAreas[row].z;
	if (row >= ConstVars::kTextDisplayAreaCount / 2)
		x -= font->MeasureTextWidth(message);
	font->Draw(message, x, y);
}

void displayStatus()
{
	drawDialougeMessage(string("Status: " + string(ConstVars::kStateMessages[gameState])).c_str(), 0);
}

void initilizeRefrences()
{
	Entity::passEngineRefrence(myEngine);
}

void preGameState()
{
	myEngine->DrawScene();
	preRender();
	drawDialougeMessage("Hit Space to Start", 3);

	hoverCar->getThirdPersonCameraMovmentEntity()->getModel()->RotateLocalY(0.4f);
	displayStatus();
	if (myEngine->KeyHit(ConstVars::kExit))
	{
		myEngine->Stop();
	}
	if (myEngine->KeyHit(ConstVars::kSpace))
	{
		resetTime();
		// Countdown timer
		hoverCar->getThirdPersonCameraMovmentEntity()->getModel()->ResetOrientation();
		gameState = GameStates::CheckeredFlagCountdown;
	}
	postRender();
}

void checkeredFlagState()
{
	preRender();
	myEngine->DrawScene(); // Draw frame
	drawDialougeMessage(string("Countdown: " + std::to_string(seccondsPassed * -1)).c_str(), 3);
	displayStatus();
	if(seccondsPassed == 0) gameState = GameStates::Playing;
	postRender();
}

void gamePlayingState()
{
	preRender();
	myEngine->DrawScene(); // Draw frame

	//Camera
	float cameraX = myEngine->GetMouseMovementX();
	float cameraY = myEngine->GetMouseMovementY();

	float cameraSlowdown = 0.5f;

	hoverCar->getThirdPersonCameraMovmentEntity()->getModel()->RotateLocalY(cameraX*cameraSlowdown);
	hoverCar->getThirdPersonCameraRotationEntity()->getModel()->RotateLocalX(cameraY*cameraSlowdown);

	if (myEngine->KeyHeld(ConstVars::kCameraUp))
	{
		hoverCar->getThirdPersonCameraRotationEntity()->getModel()->RotateLocalX(-0.1f);
	}
	if (myEngine->KeyHeld(ConstVars::kCameraDown))
	{
		hoverCar->getThirdPersonCameraRotationEntity()->getModel()->RotateLocalX(0.1f);
	}
	if (myEngine->KeyHeld(ConstVars::kCameraLeft))
	{
		hoverCar->getThirdPersonCameraMovmentEntity()->getModel()->RotateLocalY(0.4f);
	}
	if (myEngine->KeyHeld(ConstVars::kCameraRight))
	{
		hoverCar->getThirdPersonCameraMovmentEntity()->getModel()->RotateLocalY(-0.4f);
	}



	if (checkPointState - 1 < checkpoints.size())
	{
		if (Colision::sphereToSphere(hoverCar->getColisionFrontSphere(), checkpoints.at(checkPointState - 1)->checkpointSphere)||
			Colision::sphereToSphere(hoverCar->getColisionBackSphere(), checkpoints.at(checkPointState - 1)->checkpointSphere))
		{
			checkPointState++;
		}
	}
	//drawDialougeMessage(std::to_string(checkPointState).c_str(), 1);

	//Should show some message
	if (checkPointState>1)
	{
		if (checkPointState > checkpoints.size())
		{
			drawDialougeMessage("Race Complete", 1);
		}
		else
		{
			drawDialougeMessage(string("Stage " + std::to_string(checkPointState - 1) + " Complete").c_str(), 1);
		}
	}

	if(seccondsPassed < 3) drawDialougeMessage("Countdown: GO!", 3);
	displayStatus();

	// Get facing vector

	hoverCar->getMomentumEntity()->getModel()->GetMatrix(&matrix[0][0]);

	vec2 facingVector(matrix[2][0], matrix[2][2]);

	if (myEngine->KeyHit(ConstVars::kExit))
	{
		myEngine->Stop();
	}

	//HoverCar movment
	if (myEngine->KeyHeld(ConstVars::kForward))
	{
		thrust = vec2::scalar(0.005f, facingVector);
	}
	else if (myEngine->KeyHeld(ConstVars::kBackwards))
	{
		thrust = vec2::scalar(-0.005f, facingVector);
	}
	else
	{
		thrust = vec2();
	}
	if (myEngine->KeyHeld(ConstVars::kLeft))
	{
		hoverCar->getMomentumEntity()->getModel()->RotateY(-0.5f);
	}
	if (myEngine->KeyHeld(ConstVars::kRight))
	{
		hoverCar->getMomentumEntity()->getModel()->RotateY(0.5f);
	}

	



	// Calculate Drag
	drag = vec2::scalar(-0.005f, momentum);
	// Calculate Momentum
	momentum = vec2::sum(momentum, thrust, drag);
	// Check car movment
	Sphere newCarFrontSphere = hoverCar->getColisionFrontSphere();
	vec2 newCarFrontSpherePos = newCarFrontSphere.getPosition();
	newCarFrontSphere.setPositon(newCarFrontSpherePos + momentum);
	bool carHitWall = false;
	for (int i = 0; i < walls.size(); i++)
	{
		for (int j = 0; j < walls.at(i)->getHitboxes().size(); j++)
		{
			if (Colision::sphereToCube(newCarFrontSphere, *walls.at(i)->getHitboxes().at(j)))
			{
				std::cout << i << " " << j << std::endl;
				carHitWall = true;
			}
		}
	}
	if (!carHitWall)
	{
		hoverCar->getMomentumEntity()->getModel()->Move(momentum.x, 0.0f, momentum.z);
	}
	else
	{
		momentum = vec2();
	}




	// Move hover car

	postRender();
}

void(*gameStateFunctions[])() = { preGameState ,checkeredFlagState,gamePlayingState };

void main()
{
	myEngine = New3DEngine( kTLX );
	myEngine->StartWindowed();
	myEngine->AddMediaFolder(ConstVars::kMediaLocation);
	initilizeRefrences();

	new Entity("Skybox 07.x", ConstVars::kSkyboxPosition);

	new Entity("Ground.x", 0,0,0);

	walls.push_back(new Wall(vec3(-10.5, 0, 46)));
	walls.push_back(new Wall(vec3(9.5, 0, 46)));

	checkpoints.push_back(new Checkpoint(ConstVars::kCheckpointLocation1, 1));
	checkpoints.push_back(new Checkpoint(ConstVars::kCheckpointLocation2, 2));


	hoverCar = new HoverCar(ConstVars::kHoverCarStartingLocation);

	ISprite* UI = myEngine->CreateSprite("ui_backdrop.jpg", 10.0f,myEngine->GetHeight() - 60.0f - 10.0f,0.0f);
	font = myEngine->LoadFont(ConstVars::kFont, ConstVars::kFontSize);

	ICamera* camera = myEngine->CreateCamera(kManual, 0.0f, 15.0f, -50.0f);
	//camera->RotateLocalX(10.0f);

	camera->AttachToParent(hoverCar->getThirdPersonCameraRotationEntity()->getModel());
	hoverCar->getThirdPersonCameraRotationEntity()->getModel()->RotateLocalX(10.0f);
	myEngine->StartMouseCapture();
	while (myEngine->IsRunning())
	{
		gameStateFunctions[gameState]();
	}
	myEngine->StopMouseCapture();
	myEngine->Delete();
}
