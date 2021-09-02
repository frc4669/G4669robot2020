/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ArduinoCommunicator.h"
#include <iostream>

ArduinoCommunicator::ArduinoCommunicator(int baudRate)
{
  try
  {
    m_arduino = new frc::SerialPort(baudRate, frc::SerialPort::kUSB);
    std::cout << "Arduino connected on kUSB";
  } 
  catch(int e)
  {
    std::cout << "Failed to connect on kUSB, attempting kUSB1";
    try
    {
      m_arduino = new frc::SerialPort(baudRate, frc::SerialPort::kUSB1);
      std::cout << "Arduino connected on kUSB1";
    } 
    catch(int e1)
    {
      std::cout << "Failed to connect on kUSB1, attempting kUSB2";
      try
      {
        m_arduino = new frc::SerialPort(baudRate, frc::SerialPort::kUSB2);
        std::cout << "Arduino connected on kUSB2";
      } 
      catch(int e2)
      {
        std::cout << "Failed to connect on kUSB2";
      }
    }
  }
}

void ArduinoCommunicator::SendString(std::string input)
{
  m_arduino->Write(input);
  std::cout << input << '\n';
}

void ArduinoCommunicator::SendRGB(int r, int g, int b){
  std::string input = std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + "|";
  SendString(input);
}

bool ArduinoCommunicator::IsArduinoConnected()
{
  return m_arduino != nullptr;
}

std::string ArduinoCommunicator::ReceiveString(){
  m_arduino->Read(buf, 11);
  return buf;
}

// public int receiveDistance(){
//   if (m_arduino != nullptr){
//     if (buf != "")
//     {
//       buf = arduino.readString();
//     } 
//     else
//     {
//       buf += arduino.readString();
//     }

//     int i = buf.lastIndexOf("\n");
//     String in = null;
//     if(i!=-1){
//         in = buf.substring(0,i);
//         if(buf.length()>i+1)
//             buf = buf.substring(i+1);
//         else
//             buf = null;
//     }
//     if(in != null&&in.length()>0){
//         String[] str = in.split(" ");
//         // System.out.println(Arrays.toString(str));
//         if(str.length==3){
//             try{
//                 int[] distances = {-2,-2,-2};
//                 distances[0] = Integer.parseInt(str[0].trim());
//                 distances[1] = Integer.parseInt(str[1].trim());
//                 distances[2] = Integer.parseInt(str[2].trim());
//                 return distances;
//             } catch(Exception e){
//                 e.printStackTrace();
//             }
//         }
//     }
//   }
//   return null;

// }
