#include <cstddef>

#include <cstdio>
#include <raylib.h>
#include <vector>

#include "buffer.hpp"
#include "command/command.hpp"
#include "game_actor.hpp"
#include "input_handler.hpp"
#include "command/camera_command.hpp"
#include "command/game_actor_command.hpp"

game::InputHandler::InputHandler() :
  commandBuffer(8)
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

game::Buffer<game::Command<game::GameActor>*> game::InputHandler::handle_game_actor_input()
{
  this->commandBuffer.clear();

  if (IsKeyDown(KEY_W)) this->commandBuffer.append(this->buttonSetDir11);
  if (IsKeyDown(KEY_S)) this->commandBuffer.append(this->buttonSetDir12);
  if (IsKeyDown(KEY_D)) this->commandBuffer.append(this->buttonSetDir21);
  if (IsKeyDown(KEY_A)) this->commandBuffer.append(this->buttonSetDir22);

  if (IsKeyDown(KEY_SPACE)) this->commandBuffer.append(this->buttonMove);
  if (IsKeyDown(KEY_R)) this->commandBuffer.append(this->buttonRotate);

  return this->commandBuffer;
}


game::Command<Camera>* game::InputHandler::handle_camera_input()
{
  const float mouse_wheel = GetMouseWheelMove();
  if (mouse_wheel > 0.0f) return this->buttonZoomOut;
  else if  (mouse_wheel < 0.0f) return this->buttonZoomIn;

  return NULL;
}
