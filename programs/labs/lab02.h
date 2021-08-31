# include "mbed.h"
# include "crazyflie.h"

// Define motor 1 as PWM output object
PwmOut motor (MOTOR2);

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor (float omega_r)
{
    float PWM;
    PWM = omega_r*omega_r*1.184e-07 + omega_r*1.818e-12;
    return PWM;
}

// Main program
int main ()
{
    // Set PWM frequency to 500 Hzmatlab
    motor.period (1.0/500.0);

    wait(5);
    // End of program
    while ( true )
    {
         // Turn on motor 1 with 1.000 rad/s for 5 s
        motor = control_motor(1000);
        // motor = 1.7421e-5;
        wait (5);
        // Turn off motor 1
        motor = 0.0;
        wait(5);
    }
}