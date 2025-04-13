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
