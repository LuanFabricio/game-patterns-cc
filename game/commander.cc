#include "commander.hpp"
#include "game_actor.hpp"

namespace game {
	void MoveCommand::execute(game::GameActor& game_actor)
	{
		game_actor.move();
	}

	void RotateCommand::execute(game::GameActor& game_actor)
	{
		game_actor.rotate(this->angle);
	}
};
