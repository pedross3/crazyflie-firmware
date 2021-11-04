# include "mixer.h"

DigitalOut ledr(LED_RED_R, !false);
DigitalOut ledb(LED_BLUE_L, !false);

int h; // Variável de iteração do loop

// Class constructor
Mixer :: Mixer () : motor_1(MOTOR1), motor_2(MOTOR2), motor_3(MOTOR3), motor_4(MOTOR4)
{
    // Inicia todos os motores com 500 Hz e 0 de PWM.

    // Musiquinha do windows
    Play(1661, 250);
    Play(1244, 250);
    Play(830, 250);
    Play(932, 250);
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;    
    motor_1.period(1.0/500.0);
    motor_2.period(1.0/500.0);
    motor_3.period(1.0/500.0);
    motor_4.period(1.0/500.0);
    
    // I   N  I  C  I  A  L  I  Z  A  Ç  Ã  O 

    // Show de luzes
    for (h = 0; h < 15; h++) 
    {
        ledb = !ledb;
        ledr = !ledr; 
        wait(0.5);
    }

    // Fim das maracutaia;
}

// Actuate motors with desired total trust force (N) and torques (N.m)
void Mixer :: actuate (float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    // arm();
    if (armed == 1)
    {
    // Utilizamos a função criada para uma entrada de força, convertendo para omega, e saída de PWM.
    mixer(f_t, tau_phi, tau_theta, tau_psi);
    
    wait(2);
  
    motor_1 = control_motor(omega_1);
    motor_2 = control_motor(omega_2);
    motor_3 = control_motor(omega_3);
    motor_4 = control_motor(omega_4);
    
    }
    if (armed == 0)
    {
        disarm();
    }
}

// Convert total trust force (N) and torques (N.m) to angular velocities ( rad /s)
void Mixer :: mixer(float f_t, float tau_phi, float tau_theta, float tau_psi)
{
    // Faz o teste de sinal do valor de omega.
    // Como as hélices não conseguem trocar o sentido de rotação, deixa como 0.

    const float kl = 1.791e-8; //    
    const float kd = 1.436e-10; //
    
    omega_1 = (0.25*(f_t/kl-tau_phi/(kl*l)-tau_theta/(kl*l)-tau_psi/kd));
    if (omega_1 < 0)
        {omega_1 = 0;}
    else {omega_1 = sqrt(omega_1);}

    omega_2 = (0.25*(f_t/kl-tau_phi/(kl*l)+tau_theta/(kl*l)+tau_psi/kd)); // extrair raiz
    if (omega_2 < 0)
    {omega_2 = 0;}
    else {omega_2 = sqrt(omega_2);}

    omega_3 = (0.25*(f_t/kl+tau_phi/(kl*l)+tau_theta/(kl*l)-tau_psi/kd)); // extrair raiz
    if (omega_3 < 0)
        {omega_3 = 0;}
    else {omega_3 = sqrt(omega_3);}

    omega_4 = (0.25*(f_t/kl+tau_phi/(kl*l)-tau_theta/(kl*l)+tau_psi/kd)); // extrair raiz
    if (omega_4 < 0)
        {omega_4 = 0;}
    else {omega_4 = sqrt(omega_4);}
}

// Convert desired angular velocity (rad /s) to PWM signal (%)
float Mixer :: control_motor(float omega_r)
{
    float PWM;
    PWM = omega_r*omega_r*1.184e-07 + omega_r*1.818e-12;
    return PWM;
}
void Mixer::Play(float PERIODO, float TEMPO)
{   
    if (Toca_Agora == 1)
    {
        motor_1.period(1.0/PERIODO);
        motor_1 = 0.1;
        wait_ms(TEMPO);
        Toca_Agora = 2;
    }

    else if (Toca_Agora == 2) 
    {
        motor_2.period(1.0/PERIODO);
        motor_2 = 0.1;
        wait_ms(TEMPO);
        Toca_Agora = 3;
    }

    else if (Toca_Agora == 3) 
    {
        motor_3.period(1.0/PERIODO);
        motor_3 = 0.1;
        wait_ms(TEMPO);
        Toca_Agora = 4;
    }
    
    else if (Toca_Agora == 4) 
    {
        motor_4.period(1.0/PERIODO);
        motor_4 = 0.1;
        wait_ms(TEMPO);
        Toca_Agora = 1;
    }
}

void Mixer::disarm()
{
    motor_1 = 0.0;
    motor_2 = 0.0;
    motor_3 = 0.0;
    motor_4 = 0.0;
    armed = 0;
}

void Mixer::arm()
{
    armed = 1;
}
