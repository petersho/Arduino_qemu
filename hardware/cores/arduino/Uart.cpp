/*
  Copyright (c) 2015 Arduino LLC.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  
  Author: james_tsai@sonix.com.tw  2017/6/29
*/

#include "Uart.h"
#include "Arduino.h"
#define SystemFrequency 96000
/*
Uart::Uart(SERCOM *_s, uint8_t _pinRX, uint8_t _pinTX, SercomRXPad _padRX, SercomUartTXPad _padTX)
{
  sercom = _s;
  uc_pinRX = _pinRX;
  uc_pinTX = _pinTX;
  uc_padRX=_padRX ;
  uc_padTX=_padTX;
}*/

//UART initial SystemFrequency = 96MHz, Baud rate = 115200
void Uart::begin(unsigned long baudrate)
{
  //begin(baudrate, SERIAL_8N1);
  begin(baudrate, SystemFrequency);
}

void Uart::begin(unsigned long baudrate, unsigned long config)
{
  /*pinPeripheral(uc_pinRX, g_APinDescription[uc_pinRX].ulPinType);
  pinPeripheral(uc_pinTX, g_APinDescription[uc_pinTX].ulPinType);

  sercom->initUART(UART_INT_CLOCK, SAMPLE_RATE_x16, baudrate);
  sercom->initFrame(extractCharSize(config), LSB_FIRST, extractParity(config), extractNbStopBit(config));
  sercom->initPads(uc_padTX, uc_padRX);

  sercom->enableUART();*/
  
  //UART0_Init(config, baudrate);
}

void Uart::end()
{
  //sercom->resetUART();
  rxBuffer.clear();
}

void Uart::flush()
{
  //sercom->flushUART();
}

void Uart::IrqHandler()
{
  /*if (sercom->availableDataUART()) {
    rxBuffer.store_char(sercom->readDataUART());
  }

  if (sercom->isUARTError()) {
    sercom->acknowledgeUARTError();
    // TODO: if (sercom->isBufferOverflowErrorUART()) ....
    // TODO: if (sercom->isFrameErrorUART()) ....
    // TODO: if (sercom->isParityErrorUART()) ....
    sercom->clearStatusUART();
  }*/
}

int Uart::available()
{
  return rxBuffer.available();
}

int Uart::availableForWrite()
{
  //return (sercom->isDataRegisterEmptyUART() ? 1 : 0);
  return true;
}

int Uart::peek()
{
  return rxBuffer.peek();
}

int Uart::read()
{
  //return UART_GetByte();
	return 1;
}

size_t Uart::write(const uint8_t data)
{
  /*sercom->writeDataUART(data);
  return 1;*/
  
  //UART_SendByte(data);
  return 1;
}
