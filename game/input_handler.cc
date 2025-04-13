#include "commander.hpp"
#include "input_hanlder.hpp"
#include <cstddef>
#include <raylib.h>

game::InputHandler::InputHandler()
{
	this->buttonMove = new MoveCommand();
	this->buttonRotate = new RotateCommand(0.5f);
}

game::Command* game::InputHandler::handle_input()
{
	if (IsKeyPressed(KEY_W)) return buttonMove;
	if (IsKeyDown(KEY_R)) return buttonRotate;

	return NULL;
}
