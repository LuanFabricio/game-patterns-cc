#include <cstddef>

#include <raylib.h>

#include "input_hanlder.hpp"
#include "command/camera_command.hpp"
#include "command/game_actor_command.hpp"

game::InputHandler::InputHandler()
{
	this->buttonMove = new GameActorMoveCommand();
	this->buttonRotate = new GameActorRotateCommand(0.5f);
	this->buttonZoomIn = new CameraZoomInCommand(5.0f);
	this->buttonZoomOut = new CameraZoomOutCommand(5.0f);
}

game::Command<game::GameActor>* game::InputHandler::handle_game_actor_input()
{
	if (IsKeyDown(KEY_W)) return this->buttonMove;
	if (IsKeyDown(KEY_R)) return this->buttonRotate;

	return NULL;
}


game::Command<Camera>* game::InputHandler::handle_camera_input()
{
	const float mouse_wheel = GetMouseWheelMove();
	if (mouse_wheel > 0.0f) return this->buttonZoomOut;
	else if  (mouse_wheel < 0.0f) return this->buttonZoomIn;

	return NULL;
}
