#include "camera_command.hpp"

void game::CameraZoomInCommand::execute(Camera& camera, float deltaTime)
{
  camera.fovy += this->_rate;
}

void game::CameraZoomOutCommand::execute(Camera& camera, float deltaTime)
{
  camera.fovy -= this->_rate;
}
