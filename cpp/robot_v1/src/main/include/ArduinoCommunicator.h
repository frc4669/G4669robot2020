/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/SerialPort.h>

class ArduinoCommunicator {
 public:
  ArduinoCommunicator(int baudRate);

  void SendString(std::string input);

  void SendRGB(int r, int g, int b);

  bool IsArduinoConnected();

  std::string ReceiveString();

 private:
  frc::SerialPort * m_arduino = nullptr;
  char* buf = new char;
};