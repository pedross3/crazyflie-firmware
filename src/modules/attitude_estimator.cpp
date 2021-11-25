#include "attitude_estimator.h"
#include <cmath>
// Class constructor
AttitudeEstimator::AttitudeEstimator():imu(IMU_SDA, IMU_SCL)
{
    phi = 0; theta = 0; psi = 0; p = 0; q = 0; r = 0; p_bias = 0; q_bias = 0; r_bias = 0;
}

// Initialize class
 void AttitudeEstimator::init()
{
    imu.init();

    for(int i = 0; i < 500; i ++)
    {
        imu.read();
        p_bias = p_bias + imu.gx;
        q_bias = q_bias + imu.gy;
        r_bias = r_bias + imu.gz;
        
        wait(dt);
    }
    p_bias = p_bias/500;
    q_bias = q_bias/500;
    r_bias = r_bias/500;

    // Inicialização com LED vermelho
    DigitalOut ledr(LED_RED_R, !false);
    for (int h = 0; h < 15; h++) {ledr = !ledr; wait(0.2);}
    for (int h = 0; h < 30; h++) {ledr = !ledr; wait(0.05);}
    ledr = 1;
}

 // Estimate Euler angles (rad ) and angular velocities ( rad /s)
 void AttitudeEstimator::estimate ()
{
    
    imu.read();
    p = imu.gx - p_bias;
    q = imu.gy - q_bias;
    r = imu.gz - r_bias;

    // Pitch
    float phi_g = phi + p*dt;
    float phi_a = atan2(-imu.ay,-imu.az);
    phi = phi_g*(1-alpha) + phi_a*(alpha);
    
    // Roll
    float theta_g = theta + q*dt;
    float theta_a = atan2(imu.ax,-imu.az);
    theta = theta_g*(1-alpha) + theta_a*(alpha);

    // Yaw
    float psi_g = psi + r*dt;
    psi = psi_g;
}
