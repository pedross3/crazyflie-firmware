#include "mbed.h"
#include "crazyflie.h"

// Lab for measuring angular velocity as PWM value varies.

// Define Motor1 as PWM object

PwmOut motor1(MOTOR1);

// Main program

int main()
{
    while(true)
    {
        motor1.period(1.0/1000.0); motor1 = 0.2;
        wait(2);
        motor1 = 0;
    }
}