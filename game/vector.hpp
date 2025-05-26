#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <cmath>
#include <limits>
#include <raylib.h>

namespace game {

  struct Vector {
    public:
      float x, y, z;

      Vector(float x, float y, float z) : x(x), y(y), z(z) {}
      Vector(const Vector *vec) {
        this->x = vec->x;
        this->y = vec->y;
        this->z = vec->z;
      }

      game::Vector &operator+=(float const &rhs) {
        this->x += rhs;
        this->y += rhs;
        this->z += rhs;

        return *this;
      }

      game::Vector &operator+=(game::Vector const &rhs) {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;

        return *this;
      }

      game::Vector &operator*=(float const &rhs) {
        this->x *= rhs;
        this->y *= rhs;
        this->z *= rhs;

        return *this;
      }

      game::Vector operator*(float const &rhs) {
        game::Vector res(this);
        res.x *= rhs;
        res.y *= rhs;
        res.z *= rhs;

        return res;
      }

      bool operator==(game::Vector const &rhs)
      {
        const float epsilon = std::numeric_limits<float>::epsilon();
        if (std::abs(this->x - rhs.x) > epsilon) return false;
        if (std::abs(this->y - rhs.y) > epsilon) return false;
        if (std::abs(this->z - rhs.z) > epsilon) return false;
        return true;
      }

      Vector3 toRayVec3()
      {
        return (Vector3) {
          .x = this->x,
          .y = this->y,
          .z = this->z,
        };
      }

      float length()
      {
        return std::sqrtf(x*x + y*y + z*z);
      }

      void normalize()
      {
        const float length = this->length();
        if (length == 0) return;
        this->x /= length;
        this->y /= length;
        this->z /= length;
      }
  };
};

#endif // __VECTOR_HPP__
