#ifndef UTIL_H
#define UTIL_H
#define setBit(var, bitPosition) (var |= (0x01 << bitPosition))
#define togBit(var, bitPosition) (var ^= (0x01 << bitPosition))
#define clrBit(var, bitPosition) (var &= ~(0x01 << bitPosition))
#define getBit(var, bitPosition) ((var & (0x01 << bitPosition))>> bitPosition)
#endif
