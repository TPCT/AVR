#ifndef DIO_H
#define DIO_H

typedef enum{
  PORTA_t = 0,
  PORTB_t,
  PORTC_t,
  PORTD_t
} DIO_PORTID_t;

typedef enum{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
} DIO_PINID_t;

typedef enum{
    OUTPUT = 0,
    INPUT,
    INPUTPULLUP
} DIO_PIN_DIRECTION_t;

typedef enum{
  OK = 0,
  NOK
} DIOStatus_t;

typedef enum{
  LOW = 0,
  HIGH,
  NAN = -1
} DIGITAL_SIGNAL_t;

/* START PORT FUNCTIONS */
extern DIOStatus_t setDigitalPortDirection(DIO_PORTID_t Port, UINT8 mask);
extern DIOStatus_t writeDigitalPort(DIO_PORTID_t Port, UINT8 Value);
extern UINT8 readDigitalPort(DIO_PORTID_t Port);
/* END PORT FUNCTIONS */

/* START PIN FUNCTIONS */
extern DIOStatus_t setDigitalPinDirection (DIO_PORTID_t Port, DIO_PINID_t Pin, DIO_PIN_DIRECTION_t Direction);
extern DIOStatus_t writeDigitalPin(DIO_PORTID_t Port, DIO_PINID_t Pin, DIGITAL_SIGNAL_t value);
extern DIGITAL_SIGNAL_t readDigitalPin(DIO_PORTID_t Port, DIO_PINID_t Pin);
/* END PIN FUNCTIONS */

#endif
