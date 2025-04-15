#ifndef  __TERRAIN_HPP__
#define  __TERRAIN_HPP__

#include "model.hpp"

namespace game{
	struct Terrain {
		game::TerrainModel model;

		Terrain(game::TerrainModel _model): model(_model) {}
	};
}

#endif //  __TERRAIN_HPP__
