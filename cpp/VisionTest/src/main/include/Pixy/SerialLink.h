#include <frc/SerialPort.h>

class SerialLink{
    frc::SerialPort m_serial;

    void open(uint32_t arg){};
    void close(){};
    void recv(uint8_t arg1, int arg2){};
    void recv(uint8_t arg1, uint8_t arg2){};
    void recv(uint8_t arg1, uint8_t arg2, uint16_t arg3){};
    void send(uint8_t arg1, uint8_t arg2){};

};