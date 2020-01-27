#pragma once

#include <stdio.h>
#include <stdint.h>
#include <frc/Timer.h>
#include <chrono>

typedef struct {
    //void println(std::string out){wpi::outs() << out << "\n";}
    void println(char * buf) {printf("%s\n",buf);}
} SerialToUserType;

void delayMicroseconds(double microseconds) {
    double seconds = microseconds / (1000 * 1000);
    frc::Wait(seconds);
}

int millis() {
    static auto first_tick = std::chrono::steady_clock::now();
    std::chrono::duration<double> time_since_start = std::chrono::steady_clock::now() - first_tick;
    return time_since_start.count() * 1000;
}

SerialToUserType Serial;