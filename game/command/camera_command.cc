#include "camera_command.hpp"

void game::CameraZoomInCommand::execute(Camera& camera)
{
	camera.fovy += this->_rate;
}

void game::CameraZoomOutCommand::execute(Camera& camera)
{
	camera.fovy -= this->_rate;
}
