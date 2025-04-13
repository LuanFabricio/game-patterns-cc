#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

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
				res.x += rhs;
				res.y += rhs;
				res.z += rhs;

				return res;
			}

			Vector3 toRayVec3()
			{
				return (Vector3) {
					.x = this->x,
					.y = this->y,
					.z = this->z,
				};
			}
	};
};

#endif // __VECTOR_HPP__
