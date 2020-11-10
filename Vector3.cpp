#include "Vector3.h"

inline Vector3 Vector3::CrossProduct(const Vector3& v) const noexcept
{
	return Vector3(y * v.z - v.y * z, x * v.z - v.x * z, x * v.y - v.x * y);
}

inline Vector3 Vector3::Normalized() const noexcept
{
	return (*this) / Length();
}

inline void Vector3::Normalize() noexcept
{
	auto l = Length();
	x /= l;
	y /= l;
	z /= l;
}

inline float Vector3::DotProduct(const Vector3& rv) const noexcept
{
	return x * rv.x + y * rv.y + z * rv.z;
}

Vector3 Vector3::Projection(const Vector3& b) const noexcept
{
	auto aLen = Length();
	auto bLen = b.Length();
	auto dProd = DotProduct(b);
	auto cosAB = dProd / (aLen * bLen);
	return aLen / bLen * cosAB * b;
}

inline Vector3& Vector3::operator+=(const Vector3& v) noexcept
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

inline Vector3& Vector3::operator-=(const Vector3& v) noexcept
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}
