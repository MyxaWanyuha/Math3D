#pragma once
#include "Vector3.h"
#include "Rotator.h"

inline Vector3 LERP(const Vector3& a, const Vector3& b, float alpha) noexcept
{
	auto s2 = 1.f - alpha;
	return Vector3(s2 * a.x + alpha * b.x, s2 * a.y + alpha * b.y, s2 * a.z + alpha * b.z);
}

inline float Approach(float flGoal, float flCurrent, float dt)
{
	float flDif = flGoal - flCurrent;
	if (flDif > dt)
		return flCurrent + dt;
	if (flDif < -dt)
		return flCurrent - dt;
	return flGoal;
}

Vector3 RotatorToVector3(const Rotator& r) noexcept
{
	return Vector3(std::cosf(r.yaw) * std::cosf(r.pitch), std::sinf(r.pitch), std::sinf(r.yaw) * std::cosf(r.pitch));
}
