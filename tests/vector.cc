#include "gtest/gtest.h"
#include <limits>
#include <raylib.h>

#include "../game/vector.hpp"

TEST(Vector, VectorShouldMultiplyWithAValue)
{
	game::Vector v(1.0, 0.5, 0.1);

	v *= 10.0f;

	EXPECT_EQ(v.x, 10.0f);
	EXPECT_EQ(v.y, 5.0f);
	EXPECT_EQ(v.z, 1.0f);
}

TEST(Vector, VectorShouldMultiplyBinaryWithAValue)
{
	game::Vector v1(1.0f, 0.5f, 0.1f);
	game::Vector v2 = v1 * -1.0f;

	EXPECT_EQ(v2.x, -v1.x);
	EXPECT_EQ(v2.y, -v1.y);
	EXPECT_EQ(v2.z, -v1.z);
}

TEST(Vector, VectorShouldIncrementWithValue)
{
  game::Vector v1(1.0f, 0.5f, 0.1f);
  const float c = 10.f;

  v1 += c;
	EXPECT_EQ(v1.x, 11.0f);
	EXPECT_EQ(v1.y, 10.5f);
	EXPECT_EQ(v1.z, 10.1f);
}

TEST(Vector, VectorShouldIncrementWithAnotherVector)
{
  game::Vector v1(1.0f, 0.5f, 0.1f);
  game::Vector v2(-1.0f, 0.5f, 0.9f);

  v1 += v2;
	EXPECT_EQ(v1.x, 0.0f);
	EXPECT_EQ(v1.y, 1.0f);
	EXPECT_EQ(v1.z, 1.0f);
}

TEST(Vector, VectorShouldConvertToVector3) {
  game::Vector v(1.0f, 0.5f, 0.1f);
  const Vector3 vr = v.toRayVec3();

  EXPECT_EQ(v.x, vr.x);
  EXPECT_EQ(v.y, vr.y);
  EXPECT_EQ(v.z, vr.z);
}

TEST(Vector, VectorShouldReturnLength) {
  game::Vector v1(1.0f, 0.f, 0.f);
  EXPECT_EQ(v1.length(), 1.0f);

  game::Vector v2(1.0f, 1.f, 1.f);
  const float EXPECTED_LENGTH = std::sqrt(3.0f);
  EXPECT_EQ(v2.length(), EXPECTED_LENGTH);
}

TEST(Vector, VectorShouldNormalize) {
  game::Vector v1(1.0f, 0.f, 0.f);
  v1.normalize();

  EXPECT_EQ(v1.length(), 1.0f);

  game::Vector v2(10.0f, 10.f, 10.f);
  v2.normalize();
  EXPECT_LE(std::abs(v2.length()-1.0f),
      std::numeric_limits<float>::epsilon());
}
