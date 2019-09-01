#ifndef F_CPU
#define F_CPU 8000000
#endif

#include "../AVR/stdTypes.h"
#include "../DIO/DIO.h"
#include "KEYPAD_CFG.h"
#include "KEYPAD.h"
#include <util/delay.h>

UINT8 const KEYPADOUTPUTS[16] = {K0, K1, K2, K3, K4, K5, K6, K7, K8, K9, KA, KB, KC, KD, KE, KF};
KEY_t KEYPAD_GETKEY(DIO_PORTID_t Port){

  /*
          C0   C1  C2  C3
    R0     1    2   3   A
    R1     4    5   6   B
    R2     7    8   9   C
    R3     *    0   #   D
  */

  UINT8 Key = 0;
  for(UINT8 i = R0; i <= R3; i++){
    writeDigitalPin(Port, i, LOW);
    Key += (i > 0) ? 4 : 0;
    for(UINT8 j = R0; j <= R3; j++)
      if (i != j)
        writeDigitalPin(Port, j, HIGH);
    _delay_ms(10);
    if (readDigitalPin(Port, C0) == LOW)
      return (KEY_t) KEYPADOUTPUTS[Key + COL0];
    if (readDigitalPin(Port, C1) == LOW)
      return (KEY_t) KEYPADOUTPUTS[Key + COL1];
    if (readDigitalPin(Port, C2) == LOW)
      return (KEY_t) KEYPADOUTPUTS[Key + COL2];
    if (readDigitalPin(Port, C3) == LOW)
      return (KEY_t) KEYPADOUTPUTS[Key + COL3];
  }
  return NOKEY;
}
