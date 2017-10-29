#include "ConstVarables.h"

namespace ConstVars
{
	const int kFontSize = 28; // Font size
	const int kStateMessageSize = 3;
	const int kScreenWidth = 1080;
	const int kScreenHeight = 720;
	const int kDialougBoxWidth = 700;
	const int kDialougBoxHeight = 60;
	const int kDialougeScreenPadding = 10;
	const int kTextDisplayAreaCount = 4;


	const char* kMediaLocation = "./Media";
	const char* kHoverCarLocation = "race2.x";
	const char* kCheckpointLocation = "Checkpoint.x";
	const char* kDummyLocation = "Dummy.x";
	const char* kSphereLocation = "Sphere.x";
	const char* kWallLocation = "Wall.x";
	const char* kIsleStraightLocation = "IsleStraight.x";
	const char* kFont = "Comic Sans MS"; 
	const char* kStateMessages[3] = { "Main Menu" , "Countdown", "Playing"};

	const float kFZero = 0.0f;
	const float kGameSpeed = 0.30f; // Used to sync everything up to, the higher it is the faster the game logic works
	const float kRequestedFPS = 60; // FPS you want the game to run at
	const float kFrameTime = 1.0f / kRequestedFPS; // Time in microsecconds a frame should last for
	const float kSphereWidth = 20.0f;


	const EKeyCode kExit = Key_Escape; // Key for leaving the game
	const EKeyCode kForward = Key_W; // 
	const EKeyCode kBackwards = Key_S; // 
	const EKeyCode kLeft = Key_A; // 
	const EKeyCode kRight = Key_D; // 
	const EKeyCode kSpace = Key_Space; // 
	const EKeyCode kCameraUp = Key_Up; // 
	const EKeyCode kCameraDown = Key_Down; // 
	const EKeyCode kCameraLeft = Key_Left; // 
	const EKeyCode kCameraRight = Key_Right; // 


	const vec3 kSkyboxPosition(0.0f, -960.0f, 0.0f);
	const vec3 kHoverCarStartingLocation(0.0f, 0.0f, -30.0f);
	const vec3 kCheckpointLocation1(0.0f, 0.0f, 0.0f);
	const vec3 kCheckpointLocation2(0.0f, 0.0f, 100.0f);
	const vec2 kTextDisplayAreas[4] = {
		vec2(kDialougeScreenPadding ,kScreenHeight - kDialougBoxHeight - kDialougeScreenPadding),
		vec2(kDialougeScreenPadding ,kScreenHeight - kDialougBoxHeight - kDialougeScreenPadding + kFontSize),
		vec2(kDialougeScreenPadding + kDialougBoxWidth ,kScreenHeight - kDialougBoxHeight - kDialougeScreenPadding),
		vec2(kDialougeScreenPadding + kDialougBoxWidth ,kScreenHeight - kDialougBoxHeight - kDialougeScreenPadding + kFontSize)
	};
}