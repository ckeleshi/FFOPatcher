#pragma once
#define NOMINMAX
#include <Windows.h>
#include <ShlObj.h>
#include <chrono>
#include <string>
#include <utility>
#include <filesystem>

#define CHECK_SIZE(type,size) static_assert(sizeof(type)==size);
