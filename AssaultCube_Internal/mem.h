#pragma once
#include "pch.h"
#include <Windows.h>
#include <vector>


namespace mem
{
	void Patch(BYTE* dst, BYTE* src, unsigned int size);
	void Nop(BYTE* dst, unsigned int size);
	uintptr_t FindDMAAddy( uintptr_t ptr, std::vector<unsigned int> offsets);
}

//		Writing			*(int*)(*local.localPlayerPtr + o.sniperAmmo) = 1337; 
//		Reading			Vec3* Position = (Vec3*)(*local.localPlayerPtr + o.position);


template <typename T, typename Y>
T Read(Y &Base, Y &addr)
{
	T buffer{};

	buffer = (T*)(*addr);

	return buffer;
}

template <typename T, typename Y>
T Write(Y &base, Y &addr, T value)
{
	*(T*)(base + addr) = value;
	return 1;
}


