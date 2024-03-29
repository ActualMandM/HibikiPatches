﻿#pragma once

#define WIN32_LEAN_AND_MEAN

#define MOD_NAME "HibikiPatches"

// Detours
#include <Windows.h>
#include <detours.h>

// Standard library
#include <cstdint>
#include <cstdio>

// Dependencies
#include <Helpers.h>
#include <Signature.h>
#include <toml.hpp>
#include "Config.h"
