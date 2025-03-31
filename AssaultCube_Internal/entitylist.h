#pragma once
#include "offsets.h"
#include "mem.h"



void getEntList()
{
	std::cout << "\n\ngetEntList()";
	engine client{};
	entity op{};
	uintptr_t base = client.BaseMod;
	

	for (unsigned int i = 0x04; i < 128; i += 4)
	{
		uintptr_t entPosAddr = mem::FindDMAAddy(client.BaseMod + 0x18AC04, { i, offsets::position });
		op.position = (Vec3*)(entPosAddr);
		std::cout << "\nPosition [x | y | z] " << "[ " << op.position->x << " | " << op.position->y << " | " << op.position->z;
	}
	

	


	std::cout << "\n\nEntListLoop_Complete\n\n";
	system("pause");
}





