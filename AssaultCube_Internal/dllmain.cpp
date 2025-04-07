// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>
#include <thread>
#include "mem.h"
#include "aim.h"    
#include "entitylist.h"

extern "C" __declspec(dllexport) int NextHook(int code, WPARAM wParam, LPARAM lParam) { return CallNextHookEx(NULL, code, wParam, lParam); }


DWORD WINAPI HackThread(HMODULE hModule)
{
    offsets o{};
    entity local{};
    entity opponent{};
    engine client{};
    

    //create console
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << "TestOutput\n";

    

    //get module base
    
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
    local.localPlayerPtr = (uintptr_t*)(moduleBase + 0x18AC00);
    
    //entity shit is crashing the dll
    opponent.localPlayerPtr = (uintptr_t*)(moduleBase + 0x18AC04);
    uintptr_t* entity2Ptr = (uintptr_t*)(opponent.localPlayerPtr + 0x04);
   
    uintptr_t ammoAddr = mem::FindDMAAddy(moduleBase + 0x18AC00, { 0x364, 0x14, 0x0 });
    uintptr_t entHPaddr = mem::FindDMAAddy(moduleBase + 0x18AC04, { 0x04, o.health });  //THIS SOMEHOW DOES IT I WAS NOT STEPPING THROUGH THE OFFSETS CORRECTLY FINALLY
    uintptr_t entPosaddr = mem::FindDMAAddy(moduleBase + 0x18AC04, { 0x04, o.position });
 
    entity elist[32]{};
    


   //hack loop
    
    while (true)
    {
        

        //Vec3* ViewAngle = (Vec3*)(*local.localPlayerPtr + o.viewAngle);    //getting the view angles 
        //Vec3* Position = (Vec3*)(*local.localPlayerPtr + o.position);

        //maybe i should be keeping this in a global.h file and marking them extern so they can be interacted from any file

        local.position = (Vec3*)(*local.localPlayerPtr + o.position);
        local.viewAngles = (Vec3*)(*local.localPlayerPtr + o.viewAngle);   
        opponent.position = (Vec3*)(entPosaddr);
        opponent.viewAngles = (Vec3*)(*opponent.localPlayerPtr + o.viewAngle);
        local.health = *(int*)(*local.localPlayerPtr + o.health);
        opponent.health = *(int*)(entHPaddr);
        
        
       
        
        system("cls");
        std::cout << "[controls]" <<
            "\nF1 = Health\nF2 = Ammo_crashingXD\nF3 = SniperRapidFire\nF4 = RCS\nF5 = Tele test\nF6 = Aimbot\nInsert = Close\n\n" << "Ent2 Info: \n\n" 
            << opponent.position->x << ' ' << opponent.position->y << ' ' << opponent.position->z << ' HP' << opponent.health;
        
        
        //std::cout << "\n\n[][][]\n\nVecMath\n" << "Vec3Subtraction: ";
        //calcAngleA(local.position, opponent.position, *local.viewAngles);
        //calcAngleB(local.position, opponent.position);

        

       

        //key inputs
        if (GetAsyncKeyState(VK_F1) & 1)
        {
            exploit::b_health = !exploit::b_health;
            std::cout << "\nToggled Health";
        }
        if (GetAsyncKeyState(VK_F2) & 1)
        {
            exploit::b_currentAmmo = !exploit::b_currentAmmo;
            std::cout << "\nToggled Ammo";
        }
        if (GetAsyncKeyState(VK_F3) & 1)
        {
            exploit::b_rapidFire = !exploit::b_rapidFire;
            std::cout << "\nToggled RapidFire";
        }
        if (GetAsyncKeyState(VK_F4) & 1)
        {
            aim::b_RCS = !aim::b_RCS;
            std::cout << "\nToggled RecoilControlSystem";
        }
        if (GetAsyncKeyState(VK_F5) & 1)
        {
            //bTele = !bTele;
            *(float*)(*local.localPlayerPtr + o.position) = (local.position->y + 3);
        }
        if (GetAsyncKeyState(VK_F6) & 1)
        {
            aim::b_Aimbot = !aim::b_Aimbot;
            
        }
        if (GetAsyncKeyState(VK_INSERT) & 1)
        {
            break;
        }

        //writeloop

        
        
        
        

        
        

        if (local.localPlayerPtr)
        {
            if (exploit::b_health)
            {
                *(int*)(*local.localPlayerPtr + o.health) = 1337;
                //Write<int>(*local.localPlayerPtr, o.health, 1337);  //not sure if this works cant debug rn - cant think of a reasont it wouldnt work.
            }

            if (exploit::b_currentAmmo)
            {
                
                *(int*)(*local.localPlayerPtr + offsets::rifleAmmo) = 1337;       //this should write the value for current weapon ammo.
                //*(int*)(*local.localPlayerPtr + o.sniperAmmo) = 1337;
                
                
            }

            if (exploit::b_rapidFire)
            {
                
                *(int*)(*local.localPlayerPtr + o.canFire) = 0;   //when this address' value is set to 0, the sniper can be spammed.
                //Write(*local.localPlayerPtr, o.canFire, 0);
            }
            
            if (aim::b_RCS)
            {
               //*(Vec3*)(*ViewAngle.y) = ViewAngle.y - 4.8;
            }
            if (aim::b_Aimbot)
            {
                //getEntList(local.position, *local.viewAngles);
                //entlist::init();
                std::cout << "----------------------------------------\n\n\n---------------------------------------\n\n-------------------------------";
                lockOn(local.position, opponent.position, *local.viewAngles);
               // aim::b_Aimbot = !aim::b_Aimbot;
                std::cout << "\nEnd of AimbotCall";
                
            }
            if (exploit::b_tele)
            {
                //Write<float>(*local.localPlayerPtr, o.position, (Position->z + 20));
                *(float*)(*local.localPlayerPtr + o.position) = (local.position->z + 20);
            }
        }

        std::cout << "\n\n\n\n--------------------------------\n" << "LocalPlayerInfo" << "\n\nLooking: \nX:" << local.viewAngles->x << "\nY:" << local.viewAngles->y;
        std::cout << "\n\nPosition \nX:" << local.position->x << "\nY:" << local.position->y << "\nZ:" << local.position->z;
        std::cout << "\n\nHealth: " << local.health;
       
        Sleep(10);
        
        
        
        

    }

    
    

    //continuous write/freeze


    //cleanup
    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;

    //eject dll
    
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)HackThread, hModule, 0, nullptr));
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

