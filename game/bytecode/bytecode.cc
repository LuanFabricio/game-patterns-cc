#include <cstdint>
#include <cstdio>

#include "bytecode.hpp"

#define MAX_STACK_SIZE 255

game::Bytecode::Bytecode(const uint8_t* byte, const uint32_t byteSize)
{
  uint8_t stack[MAX_STACK_SIZE] = {};
  uint8_t stackCounter = 0;

  for (uint32_t i = 0; i < byteSize; i++) {
    switch (byte[i]) {
      case game::BYTECODE_CMD_STACK:
        if (stackCounter >= MAX_STACK_SIZE) {
          printf("[0x%x] Stack full\n", byte[i]);
          break;
        }
        stack[stackCounter++] = byte[++i];
        printf("Stack: ");
        for (uint8_t j = 0; j < stackCounter; j++) printf("0x%x ", stack[j]);
        printf("\n");
        break;
      case game::BYTECODE_CMD_MOVE:
        if (stackCounter <= 1) {
          printf("Command without arguments: 0x%x\n", byte[i]);
          break;
        }
        printf("Constructor args: %f, %i\n", (float)stack[stackCounter-1], stack[stackCounter-2]);
        commands_.push_back(
            new GameActorSetDirectionCommand((float)stack[stackCounter-1], (axis_e)stack[stackCounter-2])
          );
        stackCounter -= 2;
        break;
      default:
        printf("Wrong command: 0x%x\n", byte[i]);
        break;
    }
  }

  printf("Amount of commands: %lu\n", commands_.size());
}

void game::Bytecode::execute(GameActor &gameActor, float deltaTime)
{
  for (auto command : commands_) {
    command->execute(gameActor, deltaTime);
  }
}
