#ifndef __COMMANDER_GAME_ACTOR_HPP__
#define __COMMANDER_GAME_ACTOR_HPP__

#include "../game_actor.hpp"
#include "command.hpp"

namespace game {

	struct GameActorMoveCommand : public Command<GameActor> {
		public:
			virtual void execute(game::GameActor& game_actor);
	};

	struct GameActorRotateCommand : public Command<GameActor> {
		GameActorRotateCommand(float _angle = 16.f) : angle(_angle) {}
		virtual void execute(game::GameActor& game_actor);
		private:
			float angle;
	};
}

#endif // __COMMANDER_GAME_ACTOR_HPP__
