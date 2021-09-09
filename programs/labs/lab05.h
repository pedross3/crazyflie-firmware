# include "mbed.h"
# include "crazyflie.h"

// Define all motors as PWM output object
PwmOut motor1 (MOTOR1);
PwmOut motor2(MOTOR2);
PwmOut motor3 (MOTOR3);
PwmOut motor4 (MOTOR4);

// Define angular velocities (rad/s)
float omega1;
float omega2;
float omega3;
float omega4;

// Constantes do motor
const float kl = 1.791e-8;  //    
const float kd = 1.436e-10; //

// Converts desired angular velocity (rad/s) to PWM signal (%)
float control_motor (float omega_r)
{
    float PWM;
    PWM = omega_r*omega_r*1.184e-07 + omega_r*1.818e-12;
    return PWM;
}

// Converts total thrust force (N) and torques (N.m) to angular velocities (rad/s)
void mixer(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    omega1 = ( 0.25*( f_t/kl -tau_phi/(kl*l) -tau_theta/(kl*l) -tau_psi/kd) );
    if (omega1<0)
        {omega1 = 0;}
    else {omega1 = sqrt(omega1);}

    omega2 = ( 0.25*( f_t/kl -tau_phi/(kl*l) +tau_theta/(kl*l) +tau_psi/kd) ); // extrair raiz
    if (omega2<0)
    {omega2 = 0;}
    else {omega2 = sqrt(omega2);}

    omega3 = ( 0.25*( f_t/kl +tau_phi/(kl*l) +tau_theta/(kl*l) -tau_psi/kd) ); // extrair raiz
    if (omega3<0)
        {omega3 = 0;}
    else {omega3 = sqrt(omega3);}

    omega4 = ( 0.25*( f_t/kl +tau_phi/(kl*l) -tau_theta/(kl*l) +tau_psi/kd) ); // extrair raiz
    if (omega4<0)
        {omega4 = 0;}
    else {omega4 = sqrt(omega4);}
}

void actuate(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    mixer(f_t, tau_phi, tau_theta, tau_psi);
    motor1 = control_motor(omega1);
    motor2 = control_motor(omega2);
    motor3 = control_motor(omega3);
    motor4 = control_motor(omega4);
}


// Main program
int main ()
{
    // Set all PWM frequencies to 500Hz
    motor1.period(1.0/500.0);
    motor2.period(1.0/500.0);
    motor3.period(1.0/500.0);
    motor4.period(1.0/500.0);

    //Actuate motor with 70% mg total thrust force (N) and zero torques (N.m)
    wait(5);
    actuate(.7*m*g,0,0,0);
    wait(5);

    // Turn off all motors
    actuate(0,0,0,0);

    while ( true )
    {
    }
}