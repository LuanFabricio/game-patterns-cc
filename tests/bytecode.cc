#include "gtest/gtest.h"
#include <cstdint>

#include "../game/bytecode/bytecode.hpp"

TEST(Bytecode, CMD_MOVE)
{
  const uint8_t bytecodeArr[] = {
    game::BYTECODE_CMD_STACK, 0xA, // Speed
    game::BYTECODE_CMD_STACK, 0x1, // Direction Z
    game::BYTECODE_CMD_STACK, 0x1, // Direction Y
    game::BYTECODE_CMD_STACK, 0x1, // Direction X
    game::BYTECODE_CMD_STACK, 0xF, // Target Z
    game::BYTECODE_CMD_STACK, 0xA, // Target Y
    game::BYTECODE_CMD_STACK, 0x0, // Target X
    game::BYTECODE_CMD_MOVE,
    0x12
  };

  game::Bytecode behavior(bytecodeArr, sizeof(bytecodeArr));

  game::EntityModel model(Mesh{});
  game::GameActor gameActor(model, game::Vector(0, 0, 0));

  behavior.execute(gameActor, 1);

  printf("%f, %f, %f\n", gameActor.direction.x, gameActor.direction.y, gameActor.direction.z);
  EXPECT_EQ(gameActor.position.x, 0x00);
  EXPECT_EQ(gameActor.position.y, 0x0A);
  EXPECT_EQ(gameActor.position.z, 0x0A);
}

TEST(Bytecode, CMD_STACK)
{
  const uint8_t bytecodeArr[] = {
    game::BYTECODE_CMD_STACK, 0xFF,
    game::BYTECODE_CMD_STACK, 0xAA,
  };

  game::Bytecode behavior(bytecodeArr, sizeof(bytecodeArr));

  EXPECT_EQ(behavior.getStack(1), bytecodeArr[3]);
  EXPECT_EQ(behavior.getStack(0), bytecodeArr[1]);
}
