#ifndef KEYPAD_CFG_H
#define KEYPAD_CFG_H

#define R0 PIN0
#define R1 PIN1
#define R2 PIN2
#define R3 PIN3
#define C0 PIN4
#define C1 PIN5
#define C2 PIN6
#define C3 PIN7

#define K0 1
#define K1 2
#define K2 3
#define K3 'A'
#define K4 4
#define K5 5
#define K6 6
#define K7 'B'
#define K8 7
#define K9 8
#define KA 9
#define KB 'C'
#define KC '*'
#define KD 0
#define KE '#'
#define KF 'D'

extern UINT8 const KEYPADOUTPUTS[16];
typedef enum{
  KEY0 = K0,
  KEY1 = K1,
  KEY2 = K2,
  KEY3 = K3,
  KEY4 = K4,
  KEY5 = K5,
  KEY6 = K6,
  KEY7 = K7,
  KEY8 = K8,
  KEY9 = K9,
  KEYA = KA,
  KEYB = KB,
  KEYC = KC,
  KEYD = KD,
  KEYE = KE,
  KEYF = KF,
  NOKEY
} KEY_t;

#endif
