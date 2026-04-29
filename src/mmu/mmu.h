#pragma once

#include "common/common.h"
#include <iostream>
#include <fstream>
#include <array>

class MMU
{
public:
    std::array<u8, 0x4000> BIOS{};
    std::array<u8, 0x40000> EWRAM{};
    std::array<u8, 0x8000> IWRAM{};
    std::array<u8, 0x2000000> GamePak{};

    void loadRom(std::string_view filePath);

    u8 read8(u32 address);
    void write8(u32 address, u8 value);
};