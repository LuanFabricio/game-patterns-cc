#include <cstdio>

#include <raylib.h>
#include <raymath.h>

#include "game_actor.hpp"
#include "model.hpp"

void game::GameActor::move(const float frame_time)
{
  this->position += this->direction * this->speed * frame_time;
  this->updateTransform();
}

void game::GameActor::rotate(const float frame_time, const float angle)
{
  this->angle += angle * frame_time;

  this->updateTransform();
}


void game::GameActor::rotate(const float angle)
{
  const float frame_time = GetFrameTime();
  this->rotate(frame_time, angle);
}

void game::GameActor::updateTransform()
{
  Matrix translate = MatrixTranslate(
      this->position.x,
      this->position.y,
      this->position.z
      );
  Matrix rotate = MatrixRotate(this->axis.toRayVec3(), this->angle);
  this->transform = MatrixMultiply(rotate, translate);
}

Mesh game::GameActor::getMesh()
{
  return this->model.mesh;
}
