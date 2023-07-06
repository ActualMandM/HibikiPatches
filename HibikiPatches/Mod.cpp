#include "Mod.h"

SIG_SCAN
(
	sigUTOCSignature,
	0x1425CF036,
	"\x0F\x85\x00\x00\x00\x00\x40\x80\xE6\x04",
	"xx????xxxx"
);

SIG_SCAN
(
	sigPillarbox,
	0x1440522D5,
	"\xF6\x41\x30\x01\x45\x0F\x29\x43\x00",
	"xxxxxxxx?"
);

void Mod::init()
{
	if (sigValid)
	{
		WRITE_MEMORY((char*)sigUTOCSignature() + 1, uint8_t, 0x84);

		if (!Config::pillarbox)
		{
			WRITE_MEMORY((char*)sigPillarbox() + 3, uint8_t, 0);
		}
	}
	else
	{
		MessageBox(nullptr, TEXT("Failed to initialize! Please make sure that Hi-Fi RUSH is on Update 5 and try again."), TEXT("HibikiPatches"), MB_ICONERROR);
	}
}
