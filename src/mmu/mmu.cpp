#include "common/common.h"
#include "mmu/mmu.h"
#include "mmu.h"

void MMU::loadRom(std::string_view filePath)
{
    std::cout << "Attempting to load rom!\n";

    std::ifstream file(std::string(filePath), std::ios::binary);
    if (!file.is_open())
    {
        std::cout << "Failed to open file\n";
        return;
    }

    int index = 0;
    char byte;
    
    while (file.read(&byte, 1))
    {
        GamePak[index++] = static_cast<u8>(byte);
    }
}

u8 MMU::read8(u32 address)
{
    if (address >= 0 && address <= 0x00003FFF)
        return BIOS[address];
    if (address >= 0x02000000 && address <= 0x0203FFFF)
        return EWRAM[address-0x02000000];
    if (address >= 0x03000000 && address <= 0x03007FFF)
        return IWRAM[address-0x03000000];
    if (address >= 0x08000000 && address <= 0x09FFFFFF)
        return GamePak[address-0x08000000];
    return 0;
}

void MMU::write8(u32 address, u8 value)
{
    if (address >= 0 && address <= 0x00003FFF)
        BIOS[address] = value;
    if (address >= 0x02000000 && address <= 0x0203FFFF)
        EWRAM[address-0x02000000] = value;
    if (address >= 0x03000000 && address <= 0x03007FFF)
        IWRAM[address-0x03000000] = value;
    if (address >= 0x08000000 && address <= 0x09FFFFFF)
        GamePak[address-0x08000000] = value;
}