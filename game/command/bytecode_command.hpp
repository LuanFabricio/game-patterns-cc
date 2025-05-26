#ifndef __COMMAND_BYTE_CODE_HPP_
#define __COMMAND_BYTE_CODE_HPP_

#include "../game_actor.hpp"
#include "../vector.hpp"
#include "../utils.hpp"

#include "command.hpp"

namespace game {

  struct BytecodeCommandMoveTo : public Command<GameActor> {
    BytecodeCommandMoveTo(Vector target, Vector direction, float speed):
      target_(target),
      direction_(direction),
      speed_(speed) {}

    void execute(game::GameActor& gameActor, float deltaTime);
    private:
      Vector target_, direction_;
      float speed_;
      bool done_ = false;
  };
};

#endif // __COMMAND_BYTE_CODE_HPP_
