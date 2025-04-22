#ifndef __GRID2D_HPP__
#define __GRID2D_HPP__

#include <cstdint>
#include <raylib.h>
#include <vector>

#include "model.hpp"
#include "terrain.hpp"
#include "vector.hpp"

#define GRID2D_WIDTH 128
#define GRID2D_HEIGHT 128

namespace game {
  struct Grid2D {
    std::vector<Matrix>grassTransform;

    game::Terrain* grassTerrain;
    game::Terrain* grid[GRID2D_WIDTH][GRID2D_HEIGHT];

    Grid2D(game::Vector offset);

    Mesh& getMesh(uint32_t i, uint32_t j);
    Material& getMaterial(uint32_t i, uint32_t j);
    Matrix& getTransform(uint32_t i, uint32_t j);
    Model& getModel(uint32_t i, uint32_t j);

    Mesh getGrassMesh();
    Material getGrassMaterial();
  };
}

#endif // __GRID2D_HPP__
