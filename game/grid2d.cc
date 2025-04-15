#include <cstdint>
#include <cstdlib>

#include <raylib.h>
#include <raymath.h>

#include "grid2d.hpp"
#include "model.hpp"
#include "terrain.hpp"
#include "vector.hpp"

game::Grid2D::Grid2D(game::Vector offset)
{
	const float meshSize  = 30;
 	this->grassTerrain = new game::Terrain(
		game::TerrainModel(
			GenMeshCube(meshSize, meshSize, meshSize),
			LoadTexture("assets/textures/bricksx64.png")
		)
	);

	for (uint32_t i = 0; i < GRID2D_WIDTH; i++) {
		for (uint32_t j = 0; j < GRID2D_HEIGHT; j++) {
			this->grid[i][j] = this->grassTerrain;
			this->grassTransform.push_back(
				MatrixTranslate(i*meshSize + offset.x,
					offset.y,
					j*meshSize + offset.z));
		}
	}
}

Mesh& game::Grid2D::getMesh(uint32_t i, uint32_t j)
{
	return this->grid[i][j]->model.mesh;
}

Material& game::Grid2D::getMaterial(uint32_t i, uint32_t j)
{
	return this->grid[i][j]->model.material;
}

Matrix& game::Grid2D::getTransform(uint32_t i, uint32_t j)
{
	return this->grassTransform.at(i * GRID2D_WIDTH + j);
}

Model& game::Grid2D::getModel(uint32_t i, uint32_t j)
{
	return this->grid[i][j]->model.model;
}

Mesh game::Grid2D::getGrassMesh()
{
	return this->grassTerrain->model.mesh;
}

Material game::Grid2D::getGrassMaterial()
{
	this->grassTerrain->model.material.maps[MATERIAL_MAP_DIFFUSE].color = RED;
	return this->grassTerrain->model.material;
}
