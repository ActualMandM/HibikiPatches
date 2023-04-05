#include "Mod.h"

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH && Config::init())
	{
		if (Config::console)
		{
			AllocConsole();
			freopen("CONOUT$", "w", stdout);
		}

		Mod::init();
	}

	return TRUE;
}
