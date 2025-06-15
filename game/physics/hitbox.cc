#include <stdio.h>

#include "hitbox.hpp"

game::Vector game::Hitbox::getMax()
{
  return this->position + this->size;
}

bool game::Hitbox::testWith(game::Hitbox hb)
{
  const game::Vector this_max = this->getMax();
  const game::Vector hb_max = hb.getMax();

  const bool xTest = this->position.x <= hb_max.x
      && this_max.x >= hb.position.x;

  const bool yTest = this->position.y <= hb_max.y
      && this_max.y >= hb.position.y;

  const bool zTest = this->position.z <= hb_max.z
      && this_max.z >= hb.position.z;

  printf("[%b] (%f, %f) | (%f, %f)\n", xTest, position.x, this_max.x, hb.position.x, hb_max.x);
  printf("[%b] (%f, %f) | (%f, %f)\n", yTest, position.y, this_max.y, hb.position.y, hb_max.y);
  printf("[%b] (%f, %f) | (%f, %f)\n", zTest, position.z, this_max.z, hb.position.z, hb_max.z);

  return xTest && yTest && zTest;
}
