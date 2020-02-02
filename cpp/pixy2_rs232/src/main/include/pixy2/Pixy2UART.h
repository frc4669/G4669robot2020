//
// begin license header
//
// This file is part of Pixy CMUcam5 or "Pixy" for short
//
// All Pixy source code is provided under the terms of the
// GNU General Public License v2 (http://www.gnu.org/licenses/gpl-2.0.html).
// Those wishing to use Pixy source code, software and/or
// technologies under different licensing terms should contact us at
// cmucam@cs.cmu.edu. Such licensing terms are available for
// all portions of the Pixy codebase presented here.
//
// end license header
//
// Arduino UART link class, intended to be used with an Arduino with more than 1 UART,
// like the Arduino MEGA 2560.

#ifndef _PIXY2UART_H
#define _PIXY2UART_H

#include "TPixy2.h"
//#include "Arduino.h"
#include <frc/SerialPort.h>

#define PIXY_UART_BAUDRATE 19200
// TMP_BUF_SIZE must always be greater than len used in the below send and recv functions
#define TMP_BUF_SIZE 256

class Link2UART
{
public:
  frc::SerialPort * m_serial_port = nullptr;

  int8_t open(uint32_t arg)
  {
    m_serial_port = new frc::SerialPort(PIXY_UART_BAUDRATE, frc::SerialPort::kMXP);
    //m_serial_port.SetTimeout(1);
    m_serial_port->Reset();
    m_serial_port->SetReadBufferSize(1);
    m_serial_port->SetWriteBufferSize(2 * TMP_BUF_SIZE);
    m_serial_port->SetWriteBufferMode(frc::SerialPort::kFlushOnAccess);
    //if (arg == PIXY_DEFAULT_ARGVAL)
    //{
    //  //Serial1.begin(PIXY_UART_BAUDRATE);
    //  m_serial_port = frc::SerialPort(PIXY_UART_BAUDRATE);
    //} else { 
    // //Serial1.begin(arg);
    //  m_serial_port = frc::SerialPort(arg);
    //}
    return 0;
  }

  void close()
  {
    delete m_serial_port;
  }

  int16_t recv(uint8_t *buf, uint8_t len, uint16_t *cs = NULL)
  { 
    uint8_t i, j;
	int16_t c;
  char c_tmp;
    if (cs)
      *cs = 0;
    for (i=0; i<len; i++)
    {
      // wait for byte, timeout after 2ms
	  // note for a baudrate of 19.2K, each byte takes about 500us
      for (j=0; true; j++)
      {
        if (j==200)
          return -1;
	    //c = Serial1.read();
      //c = m_serial_port->Read();
      m_serial_port->Read(&c_tmp, 1);
      c = c_tmp;
        if (c>=0)
          break;
        delayMicroseconds(10);
      }
      buf[i] = c; 

      if (cs)
        *cs += buf[i];
    }
    
    return len;
    
    //roboRIO implementation
    /*
    static char tmp_buf[TMP_BUF_SIZE];
    int received_bytes = 0;
    m_serial_port->Read(&tmp_buf[0], std::min(int(len), TMP_BUF_SIZE));
    if (cs)
    {
      *cs = 0;
    }
    for (int i = 0; i < len && i < received_bytes; ++i)
    {
      buf[i] = tmp_buf[i];
      if (cs)
      {
        *cs += buf[i];
      }
    }
    return len;
    */
  }

  int16_t send(uint8_t *buf, uint8_t len)
  {
    //Serial1.write(buf, len);
    static char tmp_buf[TMP_BUF_SIZE];
    for (int i = 0; i < TMP_BUF_SIZE && i < len; ++i)
    {
      tmp_buf[i] = buf[i];
    }
    m_serial_port->Write(&tmp_buf[0], len);
    return len;
  }

private:
  uint8_t m_addr;
};

typedef TPixy2<Link2UART> Pixy2UART;

#endif
