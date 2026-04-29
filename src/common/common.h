#pragma once
#include <cstdint>

using u8 = uint8_t;
using s8 = int8_t;

using u16 = uint16_t;
using s16 = int16_t;

using u32 = uint32_t;
using s32 = int32_t;


template <typename T>
inline T setBit(T number, int index, bool set) {
    if (set) {
        return number | (static_cast<T>(1) << index);
    } else {
        return number & ~(static_cast<T>(1) << index);
    }
}

template <typename T>
inline T getBit(T number, int index)
{
    return (number >> index) & 1;
}