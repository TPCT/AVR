#ifndef SEGENSEGEMENTS_H
#define SEGENSEGEMENTS_H

#define GETUNITS(number) (number % 10)
#define GETTENTH(number) ((number / 10) % 10)
#define GETHUNDEREDTH(number) ((number / 100) % 10)
#define GETTHOUSANDTH(number) ((number / 1000) % 10)
#define GETTENSTHOUSANDTH(number) ((number / 10000) % 10)
#define GETHUNDEREDSTHOUSANDTH(number) ((number / 100000) % 10)
#define GETMILLIONTH(number) ((number / 1000000) % 10)
#define GETTENSMILLIONTH(number) ((number / 10000000) % 10)
#define GETHUNDEREDMILLIONTH(number) ((number / 100000000) % 10)

typedef enum{
  ZERO = 0x3F,
  ONE = 0x06,
  TWO = 0x5B,
  THREE = 0x4F,
  FOUR = 0x66,
  FIVE = 0x6D,
  SIX = 0x7C,
  SEVEN = 0x07,
  EIGHT = 0x7F,
  NINE = 0x6F,
  A = 0X77,
  B = 0x7F,
  C = 0x39,
  D = 0x3F,
  E = 0x79,
  F = 0x71
} SEGEMENTSNUMBERS;

extern void  clear7Segement(DIO_PORTID_t Port);
extern void  write7Segement(UINT8 Number, DIO_PORTID_t Port, bool enableHex, UINT8 Position, bool Point);
extern UINT8 getDigit(UINT64 Number,bool enableHex, UINT8 Position);

#endif
