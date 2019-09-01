#include "../AVR/stdTypes.h"
#include "../AVR/memMap.h"
#include "../DIO/DIO.h"
#include "./7Segements.h"

static UINT64 integerPower(double base, UINT64 Exponent);

void  clear7Segement(DIO_PORTID_t Port){
    writeDigitalPort(Port, 0x00);
}

void write7Segement(UINT8 Number, DIO_PORTID_t Port, bool enableHex, UINT8 Position, bool Point){
    writeDigitalPort(Port, getDigit(Number, enableHex, Position));
    Point == TRUE ? writeDigitalPin(Port, PIN7, HIGH) : 0;
}

inline UINT8 getDigit(UINT64 Number, bool enableHex, UINT8 Position){
  if (enableHex == TRUE){
    switch ((Number / integerPower(16, Position)) % 16){
      case 0:
        return ZERO;
      case 1:
        return ONE;
      case 2:
        return TWO;
      case 3:
        return THREE;
      case 4:
        return FOUR;
      case 5:
        return FIVE;
      case 6:
        return SIX;
      case 7:
        return SEVEN;
      case 8:
        return EIGHT;
      case 9:
        return NINE;
      case 10:
        return A;
      case 11:
        return B;
      case 12:
        return C;
      case 13:
        return D;
      case 14:
        return E;
      case 15:
        return F;
      default:
        return -1;
    }
  }else{
    switch ((Number / integerPower(10, Position)) % 10){
      case 0:
        return ZERO;
      case 1:
        return ONE;
      case 2:
        return TWO;
      case 3:
        return THREE;
      case 4:
        return FOUR;
      case 5:
        return FIVE;
      case 6:
        return SIX;
      case 7:
        return SEVEN;
      case 8:
        return EIGHT;
      case 9:
        return NINE;
      default:
        return -1;
    }
  }
}

static UINT64 integerPower(double base, UINT64 Exponent){
  if (Exponent == 0)
    return 1;
  while(Exponent - 1 > 0){
    base *= base;
    Exponent -= 1;
  }
  return base;
}
