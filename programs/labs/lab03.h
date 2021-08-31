# include "mbed.h"
# include "crazyflie.h"

// Define motor 1 as PWM output object
PwmOut motor1 (MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3 (MOTOR3);
PwmOut motor4 (MOTOR4);

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
    motor1.period (1.0/500.0);
    motor2.period (1.0/500.0);
    motor3.period (1.0/500.0);
    motor4.period (1.0/500.0);

    wait(5);
    // End of program
    int w;
    int desliga;

    w = 1800;
    desliga = 0;
    while ( true )
    {
         // Turn on motor 1 with 1.000 rad/s for 5 s
        motor1 = control_motor(w);
        motor2 = control_motor(w);
        motor3 = control_motor(w);
        motor4 = control_motor(w);
        // motor = 1.7421e-5;
        wait (5);
        // Turn off motor 1
        motor1 = desliga;
        motor2 = desliga;
        motor3 = desliga;
        motor4 = desliga;
        wait(5);
    }
}