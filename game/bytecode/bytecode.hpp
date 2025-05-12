#ifndef __GAME_BYTECODE_BYTECODE_HPP__
#define __GAME_BYTECODE_BYTECODE_HPP__

#include <cstdint>
#include <vector>
#include "../command/game_actor_command.hpp"

namespace game {
  enum bytecode_comand_e {
    BYTECODE_CMD_STACK = 0,
    BYTECODE_CMD_MOVE,
  };

  struct Bytecode {

    Bytecode(const uint8_t* byte, const uint32_t byteSize);
    void execute(GameActor &gameActor, float deltaTime);

    private:
      std::vector<GameActorCommand*> commands_;
  };
};
#endif // __GAME_BYTECODE_BYTECODE_HPP__
