#ifndef __MODEL_H__
#define __MODEL_H__

#include <cstdio>
#include <raylib.h>

namespace game {
  struct EntityModel {
    Mesh mesh;

    EntityModel(Mesh _mesh) : mesh(_mesh) { }
  };

  struct TerrainModel {
    Mesh mesh;
    Material material;
    Texture texture;
    Model model;

    TerrainModel(Mesh _mesh, Material _mat) : mesh(_mesh), material(_mat) { }
    TerrainModel(Mesh _mesh, Texture _texture) : mesh(_mesh), texture(_texture) {
      this->material = LoadMaterialDefault();

      this->model = LoadModelFromMesh(_mesh);
      this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = _texture;
      // model.texture = texture;
    }
  };
};

#endif // __MODEL_H__
