#include "gtest/gtest.h"
#include <cstdio>
#include <raylib.h>

#include "../../game/game_actor.hpp"
#include "../../game/model.hpp"
#include "../../game/vector.hpp"

TEST(GameActorTest, MoveShouldUpdatePlayerPosition)
{
	printf("Test\n");
	game::EntityModel model(Mesh{});
	game::GameActor ga(
		model,
		game::Vector(0, 0, 0),
		game::Vector(1, 0.5, 0)
	);

	ga.move();

	EXPECT_EQ(ga.position.x, 1);
	EXPECT_EQ(ga.position.y, 0.5);
	EXPECT_EQ(ga.position.z, 0);
}
