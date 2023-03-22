#include "Signature.h"

SIG_SCAN
(
	sigUTOCSignature,
	0x1424A4C96,
	"\x0F\x85\x00\x00\x00\x00\x40\x80\xE6\x04",
	"xx????xxxx"
);

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		WRITE_MEMORY((char*)sigUTOCSignature() + 1, uint8_t, 0x84);
	}

	return TRUE;
}
