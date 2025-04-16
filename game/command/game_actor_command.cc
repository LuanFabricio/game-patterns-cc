#include "./game_actor_command.hpp"

namespace game {
	void GameActorMoveCommand::execute(game::GameActor& game_actor)
	{
		game_actor.move();
	}

	void GameActorRotateCommand::execute(game::GameActor& game_actor)
	{
		game_actor.rotate(this->angle);
	}
};
