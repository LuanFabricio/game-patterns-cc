#ifndef __INPUT_HANDER_HPP__
#define __INPUT_HANDER_HPP__

#include "raylib.h"

#include "command/command.hpp"
#include "game_actor.hpp"

namespace game {
	struct InputHandler {
		private:
			Command<GameActor>* buttonMove;
			Command<GameActor>* buttonRotate;
			Command<Camera>* buttonZoomIn;
			Command<Camera>* buttonZoomOut;
		public:
			InputHandler();
			game::Command<GameActor>* handle_game_actor_input();
			game::Command<Camera>* handle_camera_input();
	};
}

#endif // __INPUT_HANDER_HPP__
