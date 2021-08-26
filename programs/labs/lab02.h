#include "mbed.h"
#include "crazyflie.h"

// Lab for measuring angular velocity as PWM value varies.

// Define Motor1 as PWM object
PwmOut motor1(MOTOR3);

// Main program

int main()
{
    while(true)
    {
        wait(5);
        motor1.period(1.0/500.0);
        motor1 = 0.2;
        wait(5);
        motor1 = 0;
    }
}