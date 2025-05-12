#include "gtest/gtest.h"
#include <cstdint>

#include "../game/bytecode/bytecode.hpp"

TEST(Bytecode, A)
{
  const uint8_t bytecodeArr[] = {
    game::BYTECODE_CMD_STACK, 0x0,
    game::BYTECODE_CMD_STACK, 0xA,
    game::BYTECODE_CMD_MOVE,
    0x12
  };

  game::Bytecode behavior(bytecodeArr, sizeof(bytecodeArr));

  game::EntityModel model(Mesh{});
  game::GameActor gameActor(model, game::Vector(0, 0, 0));

  behavior.execute(gameActor, 1);
  gameActor.move(1);

  printf("%f, %f, %f\n", gameActor.direction.x, gameActor.direction.y, gameActor.direction.z);
  EXPECT_EQ(gameActor.position.x, 10);
}
