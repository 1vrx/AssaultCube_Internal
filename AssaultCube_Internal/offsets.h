#pragma once
#include <libloaderapi.h>

namespace {
	namespace aim
	{

		extern bool b_RCS{ false };
		extern bool b_Aimbot{ false };

	}
	namespace visual
	{

	}
	namespace exploit
	{

		extern bool b_rapidFire{ false };
		extern bool b_rifleAmmo{ false };
		extern bool b_currentAmmo{ false };
		extern bool b_health{ false };
		extern bool b_tele{ false };

	}
	namespace client
	{

	}
}

struct Vec3 {
public:
	float x, y, z;
};

struct offsets {
public:
	
	static const uintptr_t localPlayer{ 0x18AC00 };
	static const uintptr_t entitylist{ 0x0018AC04 };
	static const uintptr_t health{0xEC};
	static const uintptr_t canFire{ 0x160 };
	static const uintptr_t rifleAmmo{ 0x140 };
	static const uintptr_t sniperAmmo{ 0x13C };
	static const uintptr_t viewAngle{0x34}; //'tis a vec3
	static const uintptr_t position{ 0x28 };//'tis a vec3
	static const uintptr_t camFOV{ 0x18A7CC };
	static const uintptr_t numOfPlayers = 0x58AC0C;
};

struct entity {
public:
	
	uintptr_t* localPlayerPtr{ nullptr };
	Vec3* viewAngles{};	// Vec3 but roll is irrelevant
	Vec3* position{};
	int health{};
};

struct engine {
public:

	const uintptr_t BaseMod{ (uintptr_t)GetModuleHandle(L"ac_client.exe") };

};

