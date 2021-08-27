# include "mbed.h"
# include "crazyflie.h"

// Define motor 1 as PWM output object
PwmOut motor (MOTOR3);

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor (float omega_r)
{
    int PWM;
    PWM = (omega_r*omega_r)*2.118e-11 - omega_r*2.543e-06 + 0.1482;
    return PWM;
}

// Main program
int main ()
{
    // Set PWM frequency to 500 Hz
    motor.period (1.0/500.0);


    // End of program
    while ( true )
    {
         // Turn on motor 1 with 1.000 rad/s for 0.5 s
        motor = control_motor(1000.0);
        wait (0.5);
        // Turn off motor 1
        motor = 0.0;
        wait(0.5);
    }
}