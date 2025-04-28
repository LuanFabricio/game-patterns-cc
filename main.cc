#include <cmath>
#include <cstdint>
#include <cstdio>
#include <sys/types.h>

#include "game/grid2d.hpp"
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#include "game/game_actor.hpp"
#include "game/input_hanlder.hpp"
#include "game/model.hpp"
#include "game/vector.hpp"

#define WINDOW_TITLE "Tower"

#define ARRAY_LEN(x, type) (sizeof(x) / sizeof(type))

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

	// game::GameActor player(
	// 	cubeModel,
	// 	game::Vector(0, 40, 0)
	// );

	game::InputHandler input_handler;

	Camera camera = {};
	camera.position = (Vector3){ -125.0f, 125.0f, -125.0f };
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	Material material = LoadMaterialDefault();
	material.maps[MATERIAL_MAP_DIFFUSE].color = BLUE;

	game::Grid2D grid(game::Vector(-125.0, -25.0f, -125.0));

	Material material2 = LoadMaterialDefault();
	material2.maps[MATERIAL_MAP_DIFFUSE].color = RED;

	game::GameActor entities[] = {
		game::GameActor(
			cubeModel,
			game::Vector(0, 0, 0)
		),
		game::GameActor(
			cubeModel,
			game::Vector(40, 0, 0)
		),
	};
	game::GameActor *player = &entities[0];

	while(!WindowShouldClose()) {
		// UpdateCamera(&camera, CAMERA_ORBITAL);
    Vector2 mousePosition = GetMousePosition();
    Ray mouseRay = GetMouseRay(mousePosition, camera);

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      for (uint32_t i = 0; i < ARRAY_LEN(entities, game::GameActor); i++) {
        game::GameActor *entity = &entities[i];
        RayCollision rc = GetRayCollisionMesh(mouseRay, entity->getMesh(), entity->transform);
        if (rc.hit) {
          player = entity;
          break;
        }
      }
    }

		BeginDrawing();

    ClearBackground(BLACK);

		BeginMode3D(camera);
			for (uint32_t i = 0; i < sizeof(entities) / sizeof(game::GameActor); i++) {
				DrawMesh(entities[i].getMesh(), material, entities[i].transform);
			}

			for (uint32_t i = 0; i < GRID2D_WIDTH; i++) {
				for (uint32_t j = 0; j < GRID2D_HEIGHT; j++) {
					Matrix translate = grid.getTransform(i, j);
					Vector3 v = {};
					v.x = translate.m12;
					v.y = translate.m13;
					v.z = translate.m14;
					DrawModel(grid.getModel(i, j),
						v, 1.0, WHITE);
				}
			}

		EndMode3D();

		EndDrawing();

		game::Command<game::GameActor>* game_actor_command = input_handler.handle_game_actor_input();
		if (game_actor_command) {
			game_actor_command->execute(*player);
		}
		input_handler.buttonMove->execute(*player);

		game::Command<Camera>* camera_command = input_handler.handle_camera_input();
		if (camera_command) {
			camera_command->execute(camera);
		}
	}


	return 0;
}
