#pragma once
#include "offsets.h"
#include "mem.h"
#include "math.h"

#include <array>

entitylist* entListPtr;// = (entitylist*)(GetModuleHandle(L"ac_client.exe") + 0x0018AC04);

void getEntList(Vec3* local, Vec3 &va)
{
	std::cout << "\n\ngetEntList()";
	engine client{};
	entity op{};
	uintptr_t base = client.BaseMod;

	entity entity[32];

	entitylist* elist;
	elist->players[2]->dist;

	
	

	for (unsigned int i = 0x04; i < 128; i += 4)
	{
		
		int entnum{};
		uintptr_t entPosAddr = mem::FindDMAAddy(client.BaseMod + 0x18AC04, { i, offsets::position });
		op.position = (Vec3*)(entPosAddr);
		//entity[entnum].position = (Vec3*)(entPosAddr);
		std::cout << "\nPosition [x | y | z] " << "\n[ " << op.position->x << " | " << op.position->y << " | " << op.position->z << " ]";
		//entity[entnum].dist = local->Distance(*entity[entnum].position);
		std::cout << "\n\nDistance from local player: " << entity[entnum].dist;
		entnum++;
	}
	
	const unsigned int i_entCount{ sizeof(entity) };
	Vec3* i_closest{};
	for (int o{}; o < i_entCount; o++)
	{
		if (i_closest > entity[o].position)
			i_closest = entity[o].position;
	}
	//va = CalcAngle(*local, *i_closest);
	


	std::cout << "\n\nEntListLoop_Complete\n\n";
	system("pause");
}

namespace entlist
{
	void init()
	{
		std::cout << "\nCalled entlist::init()\n";
		engine client{};
		unsigned int pad{ 4 };
		
		
		for (int i = 1; i < 64; i++)
		{
			pad = 0x04;
			uintptr_t posaddr = mem::FindDMAAddy(client.BaseMod + 0x18AC04, { pad , offsets::position });
			entListPtr->players[i]->position = (Vec3*)(posaddr);
			std::cout << "\n\n" << entListPtr->players[i]->position << "\n";
			pad += 0x04;

		}
			
		

		std::cout << "\n\nEntities stored";
	}
	
}





