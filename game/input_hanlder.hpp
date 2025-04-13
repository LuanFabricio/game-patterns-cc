#ifndef __INPUT_HANDER_HPP__
#define __INPUT_HANDER_HPP__

#include "commander.hpp"
namespace game {
	struct InputHandler {
		private:
			Command* buttonMove;
			Command* buttonRotate;
		public:
			InputHandler();
			game::Command* handle_input();
	};
}

#endif // __INPUT_HANDER_HPP__
