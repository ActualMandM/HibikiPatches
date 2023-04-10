#include "Mod.h"

SIG_SCAN
(
	sigUTOCSignature,
	0x1424CFAB6,
	"\x0F\x85\x00\x00\x00\x00\x40\x80\xE6\x04",
	"xx????xxxx"
);

SIG_SCAN
(
	sigPillarbox,
	0x143F675D5,
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
		versionWarning(TEXT("HibikiPatches"));
	}
}
