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
		if (sigValid)
		{
			WRITE_MEMORY((char*)sigUTOCSignature() + 1, uint8_t, 0x84);
		}
		else
		{
			MessageBox(nullptr, TEXT("Failed to initialize! Please make sure that the Hi-Fi-RUSH executable matches the MD5 hash and try again.\nMD5: 5F0E371201CB33D8813D21337526F063"), TEXT("HibikiSigPatch"), MB_ICONERROR);
		}
	}

	return TRUE;
}
