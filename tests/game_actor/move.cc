#include <cstdio>

#include "raylib.h"
#include "gtest/gtest.h"

#include "../../game/game_actor.hpp"
#include "../../game/model.hpp"
#include "../../game/vector.hpp"

TEST(GameActorTest, MoveShouldUpdatePlayerPosition)
{
	game::EntityModel model(Mesh{});
	game::GameActor ga(
		model,
		game::Vector(0, 0, 0),
		game::Vector(100.0f, 50.0f, 100.0f)
	);

	ga.move(1.0f);

	EXPECT_TRUE(ga.position.x > 0);
	EXPECT_TRUE(ga.position.y > 0);
	EXPECT_TRUE(ga.position.z > 0);
}
