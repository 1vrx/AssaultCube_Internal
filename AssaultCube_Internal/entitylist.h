#pragma once
#include "offsets.h"
#include "mem.h"



void getEntList()
{
	std::cout << "\n\ngetEntList()";
	engine client{};
	uintptr_t base = client.BaseMod;
	
	uintptr_t* e_list = (uintptr_t*)(base + offsets::entitylist);
	std::cout << "\nE_list: " << e_list << " " << &e_list;
	const int i_playerNum = *(int*)(base + offsets::numOfPlayers);
	std::cout << "\nPlayerNum: " << i_playerNum << " " << &i_playerNum;
	

	/*for (int i = 4; i < 128; i += 4)
	{
		std::cout << "\nEntList loop started\n";
		int count{1};
		int ent = *(int*)(e_list + i);
		int ent_hp = *(int*)(ent + offsets::health);
		std::cout << "\n Entity " << count << " HP: " << ent_hp << "\n";
		count++;
		Sleep(3000);
	}*/

	std::cout << "\n\nEntListLoop_Complete";
	system("pause");
}





