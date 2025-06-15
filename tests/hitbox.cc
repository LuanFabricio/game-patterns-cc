#include "gtest/gtest.h"

#include "../game/physics/hitbox.hpp"

TEST(Hitbox, testWith_should_be_true)
{
  game::Hitbox hb1(game::Vector(10, 10, 10));
  hb1.position += 5;
  game::Hitbox hb2(game::Vector(10, 10, 10));

  printf("%f, %f, %f\n", hb1.position.x, hb1.position.y, hb1.position.z);
  printf("%f, %f, %f\n", hb2.position.x, hb2.position.y, hb2.position.z);

  EXPECT_TRUE(hb1.testWith(hb2));
}

TEST(Hitbox, testWith_should_be_false)
{
  game::Hitbox hb1(game::Vector(10, 10, 10));
  hb1.position += 10.5;
  game::Hitbox hb2(game::Vector(10, 10, 10));

  printf("%f, %f, %f\n", hb1.position.x, hb1.position.y, hb1.position.z);
  printf("%f, %f, %f\n", hb2.position.x, hb2.position.y, hb2.position.z);

  EXPECT_FALSE(hb1.testWith(hb2));
}
