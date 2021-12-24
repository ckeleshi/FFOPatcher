#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <ShlObj.h>
#include <chrono>
#include <string>
#include <utility>
#include <filesystem>

#define CHECK_SIZE(type,size) static_assert(sizeof(type)==size);
