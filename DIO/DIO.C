#include "../AVR/stdTypes.h"
#include "../AVR/util.h"
#include "../AVR/memMap.h"
#include "DIO.h"

DIOStatus_t setDigitalPortDirection(DIO_PORTID_t Port, UINT8 mask){
  switch (Port) {
    case PORTA_t:
      DDRA = mask;
      break;
    case PORTB_t:
      DDRB = mask;
      break;
    case PORTC_t:
      DDRC = mask;
      break;
    case PORTD_t:
      DDRD = mask;
      break;
    default:
      return NOK;
  }
  return OK;
}

DIOStatus_t writeDigitalPort(DIO_PORTID_t Port, UINT8 Value){
    switch (Port) {
      case PORTA_t:
        PORTA = Value;
        break;
      case PORTB_t:
        PORTB = Value;
        break;
      case PORTC_t:
        PORTC = Value;
        break;
      case PORTD_t:
        PORTD = Value;
        break;
      default:
        return NOK;
    }
    return OK;
}

UINT8 readDigitalPort(DIO_PORTID_t Port){
  UINT8 value = 0;
  switch (Port) {
    case PORTA_t:
      for(int i = PIN0; i < PIN7; i++){
        getBit(PINA, i) == HIGH ? setBit(value, i) : 0;
      }
      break;
    case PORTB_t:
      for(int i = PIN0; i < PIN7; i++){
        getBit(PINB, i) == HIGH ? setBit(value, i) : 0;
      }
      break;
    case PORTC_t:
      for(int i = PIN0; i < PIN7; i++){
        getBit(PINC, i) == HIGH ? setBit(value, i) : 0;
      }
      break;
    case PORTD_t:
      for(int i = PIN0; i < PIN7; i++){
        getBit(PIND, i) == HIGH ? setBit(value, i) : 0;
      }
      break;
  }
  return value;
}

DIOStatus_t setDigitalPinDirection (DIO_PORTID_t Port, DIO_PINID_t Pin, DIO_PIN_DIRECTION_t Direction){
  switch (Port) {
    case PORTA_t:
      if (Direction == OUTPUT){
        setBit(DDRA, Pin);
      }
      else if (Direction == INPUT){
        clrBit(DDRA, Pin);
      }
      else if (Direction == INPUTPULLUP){
        clrBit(DDRA, Pin);
        setBit(PORTA, Pin);
      }
      else{
        return NOK;
      }
      break;
    case PORTB_t:
      if (Direction == OUTPUT){
        setBit(DDRB, Pin);
      }
      else if (Direction == INPUT){
        clrBit(DDRB, Pin);
      }
      else if (Direction == INPUTPULLUP){
        clrBit(DDRB, Pin);
        setBit(PORTB, Pin);
      }
      else{
        return NOK;
      }
      break;
    case PORTC_t:
      if (Direction == OUTPUT){
        setBit(DDRC, Pin);
      }
      else if (Direction == INPUT){
        clrBit(DDRC, Pin);
      }
      else if (Direction == INPUTPULLUP){
        clrBit(DDRC, Pin);
        setBit(PORTC, Pin);
      }
      else{
        return NOK;
      }
    case PORTD_t:
      if (Direction == OUTPUT){
        setBit(DDRD, Pin);
      }
      else if (Direction == INPUT){
        clrBit(DDRD, Pin);
      }
      else if (Direction == INPUTPULLUP){
        clrBit(DDRD, Pin);
        setBit(PORTD, Pin);
      }
      else{
        return NOK;
      }
      break;
    default:
      return NOK;
  }
  return OK;
}

DIOStatus_t writeDigitalPin(DIO_PORTID_t Port, DIO_PINID_t Pin, DIGITAL_SIGNAL_t value){
    switch (Port) {
      case PORTA_t:
        value == HIGH ? setBit(PORTA, Pin) : clrBit(PORTA, Pin);
        break;
      case PORTB_t:
        value == HIGH ? setBit(PORTB, Pin) : clrBit(PORTB, Pin);
        break;
      case PORTC_t:
        value == HIGH ? setBit(PORTC, Pin) : clrBit(PORTC, Pin);
        break;
      case PORTD_t:
        value == HIGH ? setBit(PORTD, Pin) : clrBit(PORTD, Pin);
        break;
      default:
        return NOK;
    }
    return OK;
}

DIGITAL_SIGNAL_t readDigitalPin(DIO_PORTID_t Port, DIO_PINID_t Pin){
  switch (Port) {
    case PORTA_t:
      return (Pin >= PIN0 && Pin <= PIN7) ? (DIGITAL_SIGNAL_t) getBit(PINA, Pin) : NAN;
    case PORTB_t:
      return (Pin >= PIN0 && Pin <= PIN7) ? (DIGITAL_SIGNAL_t) getBit(PINB, Pin) : NAN;
    case PORTC_t:
      return (Pin >= PIN0 && Pin <= PIN7) ? (DIGITAL_SIGNAL_t) getBit(PINC, Pin) : NAN;
    case PORTD_t:
      return (Pin >= PIN0 && Pin <= PIN7) ? (DIGITAL_SIGNAL_t) getBit(PIND, Pin) : NAN;
      break;
    default:
      return NAN;
  }
}
