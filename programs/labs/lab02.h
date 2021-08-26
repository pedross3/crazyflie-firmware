#include "mbed.h"
#include "crazyflie.h"

// Lab for measuring angular velocity as PWM value varies.

// Define Motor1 as PWM object
PwmOut motor1(MOTOR3);

// Main program

int main()
{
    motor1.period(1.0/500.0);
    while(true)
    {
        // wait(5);
        // 
        // motor1 = 1;
        // wait(5);
        // motor1 = 0;

        // Parte 2:
        
    }
}