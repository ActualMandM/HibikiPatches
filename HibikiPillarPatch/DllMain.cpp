#include "Signature.h"

SIG_SCAN
(
	sigPillarbox,
	0x143F283C5,
	"\xF6\x41\x30\x01\x45\x0F\x29\x43\x00",
	"xxxxxxxx?"
);

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		if (sigValid)
		{
			WRITE_MEMORY((char*)sigPillarbox() + 3, uint8_t, 0);
		}
		else
		{
			versionWarning(TEXT("HibikiPillarPatch"));
		}
	}

	return TRUE;
}
