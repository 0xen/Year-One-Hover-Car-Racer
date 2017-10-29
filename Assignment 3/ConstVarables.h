#pragma once

#include "Vec.h"
#include <TL-Engine.h>
using namespace tle;

namespace ConstVars
{
	extern const int kFontSize; // Font size
	extern const int kStateMessageSize;
	extern const int kScreenWidth;
	extern const int kScreenHeight;
	extern const int kDialougBoxWidth;
	extern const int kDialougBoxHeight;
	extern const int kDialougeScreenPadding;
	extern const int kTextDisplayAreaCount;

	extern const char* kMediaLocation;
	extern const char* kHoverCarLocation;
	extern const char* kCheckpointLocation;
	extern const char* kDummyLocation;
	extern const char* kSphereLocation;
	extern const char* kWallLocation;
	extern const char* kIsleStraightLocation;
	extern const char* kFont;
	extern const char* kStateMessages[3];

	extern const float kFZero;
	extern const float kGameSpeed; // Used to sync everything up to, the higher it is the faster the game logic works
	extern const float kRequestedFPS; // FPS you want the game to run at
	extern const float kFrameTime; // Time in microsecconds a frame should last for
	extern const float kSphereWidth;


	extern const EKeyCode kExit; // Key for leaving the game
	extern const EKeyCode kForward; // 
	extern const EKeyCode kBackwards; // 
	extern const EKeyCode kLeft; // 
	extern const EKeyCode kRight; // 
	extern const EKeyCode kSpace; // 
	extern const EKeyCode kCameraUp; // 
	extern const EKeyCode kCameraDown; // 
	extern const EKeyCode kCameraLeft; // 
	extern const EKeyCode kCameraRight; // 


	//Posiitons
	extern const vec3 kSkyboxPosition;
	extern const vec3 kHoverCarStartingLocation;
	extern const vec3 kCheckpointLocation1;
	extern const vec3 kCheckpointLocation2;
	extern const vec2 kTextDisplayAreas[4];
}