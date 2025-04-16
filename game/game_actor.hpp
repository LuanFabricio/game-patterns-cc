#ifndef __GAME_ACTOR_HPP__
#define __GAME_ACTOR_HPP__

#include <raylib.h>
#include <raymath.h>

#include "model.hpp"
#include "vector.hpp"

namespace game {

	struct GameActor {
		private:
			void updateTransform();
		public:
			game::Vector position;
			game::Vector speed;
			game::Vector axis;
			float angle;

			Matrix transform;

			EntityModel model;

			GameActor(
				EntityModel _model,
				game::Vector _pos,
				game::Vector _speed,
				game::Vector _axis = game::Vector(0, 1, 0),
				float _angle = 0
			) : position(_pos), speed(_speed),
				axis(_axis), angle(_angle), model(_model){
				this->transform = MatrixTranslate(_pos.x, _pos.y,  _pos.z);
				Matrix rotate = MatrixRotate(_axis.toRayVec3(), angle);
				this->transform = MatrixMultiply(this->transform, rotate);
			}

			void move(const float frame_time);
			void move();
			void rotate(const float frame_time, const float angle);
			void rotate(const float angle);

			Mesh getMesh();
	};
};

#endif // __GAME_ACTOR_HPP__
