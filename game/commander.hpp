#ifndef __COMMANDER_HPP__
#define __COMMANDER_HPP__

#include "game_actor.hpp"

namespace game {
	struct Command {
		virtual ~Command() {}
		virtual void execute(game::GameActor& game_actor) = 0;
	};

	struct MoveCommand : public game::Command {
		public:
			virtual void execute(game::GameActor& game_actor);
	};

	struct RotateCommand : public game::Command {
		private:
			float angle;
		public:
			RotateCommand(float _angle = 16.f) : angle(_angle) {}
			virtual void execute(game::GameActor& game_actor);
	};
}

#endif // __COMMANDER_HPP__
