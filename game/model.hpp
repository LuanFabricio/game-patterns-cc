#ifndef __MODEL_H__
#define __MODEL_H__

#include <raylib.h>

namespace game {
	struct EntityModel {
		Mesh mesh;

		EntityModel(Mesh _mesh) : mesh(_mesh) { }
	};
};

#endif // __MODEL_H__
