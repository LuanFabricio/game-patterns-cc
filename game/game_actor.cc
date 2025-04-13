#include <cstdio>

#include <raylib.h>
#include <raymath.h>

#include "game_actor.hpp"
#include "model.hpp"

void game::GameActor::move()
{
	float frame_time = GetFrameTime();
	this->position += this->speed * frame_time;

	this->updateTransform();
}

void game::GameActor::rotate(const float angle)
{
	float frame_time = GetFrameTime();
	this->angle += angle * frame_time;

	this->updateTransform();
}

void game::GameActor::updateTransform()
{
	Matrix translate = MatrixTranslate(
		this->position.x,
		this->position.y,
		this->position.z
	);
	Matrix rotate = MatrixRotate(this->axis.toRayVec3(), this->angle);
	this->transform = MatrixMultiply(rotate, translate);
}

Mesh game::GameActor::getMesh()
{
	return this->model.mesh;
}
