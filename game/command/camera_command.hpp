#ifndef __COMMANDER_CAMERA_HPP__
#define __COMMANDER_CAMERA_HPP__

#include "command.hpp"
#include <raylib.h>

namespace game {
	struct CameraZoomInCommand : public Command<Camera> {
		public:
			CameraZoomInCommand(float rate = -1.f) : _rate(rate) {}
			virtual void execute(Camera& camera);

		private:
			float _rate;
	};

	struct CameraZoomOutCommand : public Command<Camera> {

		CameraZoomOutCommand(float rate = 1.0f) : _rate(rate) {}
		virtual void execute(Camera& camera);

		private:
			float _rate;
	};
}

#endif // __COMMANDER_CAMERA_HPP__
