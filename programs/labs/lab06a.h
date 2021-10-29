# include "mbed.h"
# include "modules/mixer.h"

// Main program
int main ()
{
// Declare mixer
Mixer mixer;

    // Actuate motor with 70% mg total thrust force (N) and zero torques
    mixer.actuate (0.7*m*g, 0, 0, 0) ;
    wait(5);
    // Turn off all motors
    mixer.actuate(0, 0, 0, 0);
    // End of program
    wait(5);
    while(true)
    {
        mixer.actuate(0.2, 0, 0, 0);
    }
}