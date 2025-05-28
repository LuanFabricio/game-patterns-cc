#include <cstdio>
#include "bytecode_command.hpp"

constexpr double epsilon = 1e-1;

void game::BytecodeCommandMoveTo::execute(game::GameActor& gameActor, float deltaTime)
{
  if (gameActor.position == target_ || direction_.length() == 0) {
    done_ = true;
    return;
  }
  if (done_) return;

  if (std::abs(gameActor.position.x - target_.x) <= epsilon) {
    direction_.x = 0;
    gameActor.position.x = target_.x;
  }
  if (std::abs(gameActor.position.y - target_.y) <= epsilon) {
    direction_.y = 0;
    gameActor.position.y = target_.y;
  }
  if (std::abs(gameActor.position.z - target_.z) <= epsilon) {
    direction_.z = 0;
    gameActor.position.z = target_.z;
  }

  printf("%f <= %lf\n", std::abs(gameActor.position.x - target_.x), epsilon);
  printf("%f <= %lf\n", std::abs(gameActor.position.y - target_.y), epsilon);
  printf("%f <= %lf\n", std::abs(gameActor.position.z - target_.z), epsilon);

  printf("%f, %f, %f != %f, %f, %f\n",
      target_.x, target_.y, target_.z,
      gameActor.position.x, gameActor.position.y, gameActor.position.z);
  printf("Speed: %f\n", gameActor.speed);

  gameActor.direction = direction_;
  printf("%f, %f, %f\n",
      gameActor.direction.x, gameActor.direction.y, gameActor.direction.z);
  gameActor.speed = speed_;
  gameActor.move(deltaTime);
}
