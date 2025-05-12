#ifndef __INPUT_HANDER_HPP__
#define __INPUT_HANDER_HPP__

#include "buffer.hpp"
#include "raylib.h"

#include "command/command.hpp"
#include "game_actor.hpp"

namespace game {
  struct InputHandler {
    private:
      Command<GameActor>* buttonRotate;
      Command<GameActor>* buttonSetDir11;
      Command<GameActor>* buttonSetDir12;
      Command<GameActor>* buttonSetDir21;
      Command<GameActor>* buttonSetDir22;
      Command<Camera>* buttonZoomIn;
      Command<Camera>* buttonZoomOut;

      Buffer<Command<GameActor>*> commandBuffer;
    public:
      Command<GameActor>* buttonMove;
      InputHandler();
      game::Buffer<game::Command<game::GameActor>*> handle_game_actor_input();
      game::Command<Camera>* handle_camera_input();
  };
}

#endif // __INPUT_HANDER_HPP__
