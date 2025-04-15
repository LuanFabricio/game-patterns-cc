#include "gtest/gtest.h"

#include "../../game/vector.hpp"

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
