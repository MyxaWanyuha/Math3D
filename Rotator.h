#pragma once
struct Rotator
{
	float pitch, yaw, roll;
	Rotator(float Pitch = 0.f, float Yaw = 0.f, float Roll = 0.f) noexcept
		:pitch(Pitch), yaw(Yaw), roll(Roll) {};

	void Normalize() noexcept;
};

