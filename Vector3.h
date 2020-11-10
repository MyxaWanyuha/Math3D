#pragma once
#include <cmath>
struct Vector3
{
	float x, y, z;
	Vector3(float X = 0.f, float Y = 0.f, float Z = 0.f) noexcept
		:x(X), y(Y), z(Z) {};
	float Length() const noexcept { return std::sqrtf(x * x + y * y + z * z); }
	Vector3 Normalized() const noexcept;
	void Normalize() noexcept;
	float DotProduct(const Vector3& rv) const noexcept;
	Vector3 CrossProduct(const Vector3& v) const noexcept;

	//Projection of this onto vector b
	Vector3 Projection(const Vector3& b) const noexcept;

	Vector3& operator+=(const Vector3& v) noexcept;
	Vector3& operator-=(const Vector3& v) noexcept;
};


inline Vector3 operator-(const Vector3& lv, const Vector3& rv) noexcept
{
	return Vector3(lv.x - rv.x, lv.z - rv.z, lv.z - rv.z);
}

inline Vector3 operator+(const Vector3& lv, const Vector3& rv) noexcept
{
	return Vector3(lv.x + rv.x, lv.z + rv.z, lv.z + rv.z);
}

inline Vector3 operator*(const Vector3& v, float s) noexcept
{
	return Vector3(v.x * s, v.y * s, v.z * s);
}

inline Vector3 operator/(const Vector3& v, float s) noexcept
{
	return Vector3(v.x / s, v.y / s, v.z / s);
}

inline Vector3 operator*(float s, const Vector3& v) noexcept
{
	return v * s;
}

inline Vector3 operator/(float s, const Vector3& v) noexcept
{
	return v / s;
}
