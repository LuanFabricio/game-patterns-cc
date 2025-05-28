#ifndef __GAME_BYTECODE_BYTECODE_HPP__
#define __GAME_BYTECODE_BYTECODE_HPP__

#include <cstdint>
#include <vector>
#include "../command/game_actor_command.hpp"
#include "../game_actor.hpp"

namespace game {
  enum bytecode_comand_e {
    BYTECODE_CMD_STACK = 0,
    BYTECODE_CMD_MOVE,
  };

  struct Bytecode {

    Bytecode(const uint8_t* byte, const uint32_t byteSize);

    static Bytecode fromFile(const char* filename);

    void execute(GameActor &gameActor, float deltaTime);
    int16_t getStack(uint8_t i);

    private:
      static const uint8_t MAX_STACK_SIZE = 255;

      uint8_t stack_[MAX_STACK_SIZE] = {};
      uint8_t stackCounter_ = 0;
      bool loop_ = false;

      std::vector<GameActorCommand*> commands_;
      uint8_t commandCounter_ = 0;

      game::Command<game::GameActor>* handle_move(
          uint8_t stack[MAX_STACK_SIZE],  uint8_t &stackCounter);
  };
};
#endif // __GAME_BYTECODE_BYTECODE_HPP__
