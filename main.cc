#include <cmath>
#include <cstdio>

#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#include "game/commander.hpp"
#include "game/game_actor.hpp"
#include "game/input_hanlder.hpp"
#include "game/model.hpp"
#include "game/vector.hpp"

#define WINDOW_TITLE "Tower"

struct player_t {
	Vector2 pos, speed, speed_vector;

	player_t(Vector2 pos, Vector2 speed=Vector2{1, 1}) : pos(pos), speed(speed){ }

	void move(float delta_time)
	{
		this->pos.x += this->speed.x * delta_time;
		this->pos.y += this->speed.y * delta_time;
	}

	void normalize_speed()
	{
		float x2 = this->speed.x * this->speed.x;
		float y2 = this->speed.y * this->speed.y;

		float len = std::sqrtf(x2+y2);

		this->speed.x /= len;
		this->speed.y /= len;
	}
};

int main(void)
{
	InitWindow(800, 600, WINDOW_TITLE);

	// player_t player(Vector2{.x=15, .y=15}, Vector2{1, 2});
	game::EntityModel cubeModel(GenMeshCube(25, 25, 25));

	game::GameActor player(
		cubeModel,
		game::Vector(40, 40, 10),
		game::Vector(10, 10, 10)
	);

	game::InputHandler input_handler;

	Camera camera = { 0 };
	camera.position = (Vector3){ -125.0f, 125.0f, -125.0f };
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	Material material = LoadMaterialDefault();
	material.maps[MATERIAL_MAP_DIFFUSE].color = BLUE;
	Matrix translation = MatrixTranslate(0, 0, 0);
	Vector3 axis = {
		.x = (float)GetRandomValue(0, 360),
		.y = (float)GetRandomValue(0, 360),
		.z = (float)GetRandomValue(0, 360),
	};
	axis = Vector3Normalize(axis);
	float angle = (float)GetRandomValue(0, 180);
	Matrix rotation = MatrixRotate(axis, angle);
	Matrix transform = MatrixMultiply(translation, rotation);

	while(!WindowShouldClose()) {
		// UpdateCamera(&camera, CAMERA_ORBITAL);

		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode3D(camera);
			DrawMesh(player.getMesh(), material, player.transform);
		EndMode3D();

		EndDrawing();

		game::Command* command = input_handler.handle_input();
		if (command) {
			command->execute(player);
		}
	}

	return 0;
}
