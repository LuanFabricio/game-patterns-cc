#include <cstdint>
#include <cstdio>

#include "../command/bytecode_command.hpp"
#include "bytecode.hpp"

game::Bytecode::Bytecode(const uint8_t* byte, const uint32_t byteSize)
{
  for (uint32_t i = 0; i < byteSize; i++) {
    switch (byte[i]) {
      case game::BYTECODE_CMD_STACK:
        if (stackCounter_ >= MAX_STACK_SIZE) {
          printf("[0x%x] Stack full\n", byte[i]);
          break;
        }
        stack_[stackCounter_++] = byte[++i];
        printf("Stack: ");
        for (uint8_t j = 0; j < stackCounter_; j++) printf("0x%x ", stack_[j]);
        printf("\n");
        break;
      case game::BYTECODE_CMD_MOVE:
        if (stackCounter_ <= 6) {
          printf("Command without arguments: 0x%x\n", byte[i]);
          break;
        }

        commands_.push_back(handle_move(stack_, stackCounter_));
        break;
      default:
        printf("Wrong command: 0x%x\n", byte[i]);
        break;
    }
  }

  printf("Amount of commands: %lu\n", commands_.size());
}

game::Bytecode game::Bytecode::fromFile(const char* filename)
{
  FILE *file = fopen(filename, "rb");
  fseek(file, 0L, SEEK_END);
  uint32_t byteSize = ftell(file);
  uint8_t *byte = (uint8_t*)malloc(sizeof(uint8_t) * byteSize);
  fseek(file, 0L, SEEK_SET);

  fread(byte, sizeof(uint8_t), byteSize, file);

  fclose(file);

  return game::Bytecode(byte, byteSize);
}

void game::Bytecode::execute(GameActor &gameActor, float deltaTime)
{
  if (commandCounter_ >= commands_.size()) commandCounter_ = 0;
  auto command = commands_.at(commandCounter_);
  command->execute(gameActor, deltaTime);
  commandCounter_ += 1;
}

int16_t game::Bytecode::getStack(uint8_t i)
{
  if (i < stackCounter_) {
    return stack_[i];
  }

  return -1;
}

game::Command<game::GameActor>* game::Bytecode::handle_move(
    uint8_t stack[MAX_STACK_SIZE],  uint8_t &stackCounter)
{
  game::Vector target(
    stack[stackCounter-1],
    stack[stackCounter-2],
    stack[stackCounter-3]
  );
  game::Vector direction(
    stack[stackCounter-4],
    stack[stackCounter-5],
    stack[stackCounter-6]
  );
  float speed = stack[stackCounter_-7];
  stackCounter -= 7;
  printf("Constructor args:\n"
      "\tTarget: %f, %f, %f\n"
      "\tDirection: %f, %f, %f\n"
      "\tSpeed: %f\n",
      target.x, target.y, target.z,
      direction.x, direction.y, direction.z,
      speed);

  game::Command<game::GameActor>* gameActorCommand = new BytecodeCommandMoveTo(
    target, direction, speed);
  return gameActorCommand;
}
