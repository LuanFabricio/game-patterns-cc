#include <cstddef>

#include <raylib.h>

#include "input_hanlder.hpp"
#include "command/camera_command.hpp"
#include "command/game_actor_command.hpp"

game::InputHandler::InputHandler()
{
  this->buttonMove = new GameActorMoveCommand();
  this->buttonRotate = new GameActorRotateCommand(0.5f);

  this->buttonSetDir11 = new GameActorSetDirectionCommand(1.0f, axis_e::AXIS_X);
  this->buttonSetDir12 = new GameActorSetDirectionCommand(-1.0f, axis_e::AXIS_X);
  this->buttonSetDir21 = new GameActorSetDirectionCommand(1.0f, axis_e::AXIS_Z);
  this->buttonSetDir22 = new GameActorSetDirectionCommand(-1.0f, axis_e::AXIS_Z);

  this->buttonZoomIn = new CameraZoomInCommand(5.0f);
  this->buttonZoomOut = new CameraZoomOutCommand(5.0f);
}

game::Command<game::GameActor>* game::InputHandler::handle_game_actor_input()
{
  if (IsKeyDown(KEY_W)) return this->buttonSetDir11;
  if (IsKeyDown(KEY_S)) return this->buttonSetDir12;
  if (IsKeyDown(KEY_D)) return this->buttonSetDir21;
  if (IsKeyDown(KEY_A)) return this->buttonSetDir22;

  if (IsKeyDown(KEY_SPACE)) return this->buttonMove;
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
