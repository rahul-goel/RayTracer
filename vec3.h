#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

class vec3 {
	public:
		double e[3];

		vec3() : e{0, 0, 0} {}
		vec3(double x, double y, double z) : e{x, y, z} {}

		double x() { return e[0]; }
		double y() { return e[1]; }
		double z() { return e[2]; }

		vec3 operator - () {
			return vec3(-e[0], -e[1], -e[2]);
		}

		double operator [] (int i) const {
			return e[i];
		}

		double& operator [] (int i) {
			return e[i];
		}

		vec3& operator += (const vec3 v) {
			for (int i = 0; i < 3; i++) e[i] += v[i];
			return *this;
		}

		vec3& operator *= (const double t) {
			for (int i = 0; i < 3; i++) e[i] *= t;
			return *this;
		}

		vec3& operator /= (const double t) {
			return *this *= 1/t;
		}

		double length_squared() const {
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}

		double length() const {
			return sqrt(length_squared());
		}
};

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3 &v) {
	return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
	return t * v;
}

inline vec3 operator/(vec3 v, double t) {
	return (1/t) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
	return u.e[0] * v.e[0]
		+ u.e[1] * v.e[1]
		+ u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
			u.e[2] * v.e[0] - u.e[0] * v.e[2],
			u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}

using point3 = vec3;   // 3D point
using color = vec3;    // RGB color

#endif
