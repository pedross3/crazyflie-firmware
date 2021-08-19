#include "mbed.h"
#include "crazyflie.h"

// Define all LEDs as digital output objects
// Define red LED (right) as digital output object

DigitalOut ledr(LED_RED_R, !false);
DigitalOut ledb(LED_BLUE_L, !false);
BusOut ledg(LED_GREEN_L, LED_GREEN_R);

// Define all motors as PWM objects
PwmOut motor1(MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3(MOTOR3);
PwmOut motor4(MOTOR4);
int h;

// Main program
int main()
{// Main program
    while(true)
    {
    // Blink blue LED indicating inicialization (5 seconds)
    for (h = 0; h < 3; h++) 
    {ledb = !ledb; wait(0.2);}
    // Blink LED every second
    for (h = 0; h < 3; h++) 
    {ledb = !ledb; ledr = !ledr; wait(0.2);}

    // Turn on red LEDs indicating motors are armed
    ledr = 1;
    // Test all motors with different frequencies (to make different noises)
        // Turn motor on (20% power) and off every second

        motor1.period(1.0/1000.0); motor1 = 0.2;
        wait(0.5);
        motor1 = 0;

        motor2.period(1.0/800); motor2 = 0.2;
        wait(0.5);
        motor2 = 0;
        
        motor3.period(1.0/600); motor3 = 0.2;
        wait(0.5);
        motor3 = 0;


        motor4.period(1.0/400); motor4 = 0.2;
        wait(0.5);
        motor4 = 0;
        
        motor1 = 0; wait(0.5);
        motor2 = 0; wait(0.5);
        motor3 = 0; wait(0.5);
        motor4 = 0; wait(0.5);
    }
    // Turn off red LEDs indicating motors are disarmed
    ledr = 0;
    // Blink green LEDs indicating end of program
    for (h = 0; h < 3; h++) 
    {ledb = !ledb; wait(0.2);}

}

