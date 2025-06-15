#ifndef __PHYSICS_HITBOX_HPP__
#define __PHYSICS_HITBOX_HPP__

#include "../vector.hpp"

namespace game {
  struct Hitbox {
    game::Vector position;
    game::Vector size;

    Hitbox(game::Vector size):
      position(game::Vector(0, 0, 0)),
      size(size) { }
    Hitbox(game::Vector _position, game::Vector _size):
      position(_position),
      size(_size) { }

    bool testWith(game::Hitbox hb);
    Vector getMax();
  };
};

#endif // __PHYSICS_HITBOX_HPP__
