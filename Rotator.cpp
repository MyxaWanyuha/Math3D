#include "Rotator.h"

void Rotator::Normalize() noexcept
{
	pitch = (pitch > 89.f) * 89.f + (pitch < -89.f) * -89.f + (pitch <= 89.f && pitch >= -89.f) * pitch;
	//if (pitch > 89.f)
	//	pitch = 89.f;
	//if (pitch < -89.f)
	//	pitch = -89.f;
	while (yaw < -180)
		yaw += 360;
	while (yaw > 180)
		yaw -= 360;
}
