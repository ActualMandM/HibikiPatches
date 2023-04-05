#include "Config.h"

bool Config::console;
bool Config::pillarbox;

bool Config::init()
{
    toml::table config;

    try
    {
        config = toml::parse_file("HibikiPatches.toml");
    }
    catch (std::exception& exception)
    {
        char text[1024];
        sprintf_s(text, "Failed to parse HibikiPatches.toml:\n%s", exception.what());
        MessageBoxA(nullptr, text, "HibikiPatches", MB_OK | MB_ICONERROR);
    }

    if (!config["enabled"].value_or(true))
        return false;

    console = config["console"].value_or(false);
    pillarbox = config["pillarbox"].value_or(true);

    return true;
}
