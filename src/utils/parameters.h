#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2

// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

const float Motor_kl = 1.791e-8;  //    
const float Motor_kd = 1.436e-10; //

// Lab 07 parameters
const float dt = 2e-3; // 500 Hz

const float wc_roll = 1;
const float alpha_roll = 1 - wc_roll*dt/(1+wc_roll*dt);

const float wc_pitch = 5;
const float alpha_pitch = 1 - wc_pitch*dt/(1+wc_pitch*dt);

// Lab 08 parameters
const float Ts = 0.4;
const float os = 0.5/100;

const float zeta = abs(log(os))/(sqrt(pow(log(os),2)+pow(pi,2)));
const float omega_n = 4/(zeta*Ts);

const float kd_rp = 2*zeta*omega_n; //kd e kp para roll e pitch
const float kp_rp = pow(omega_n,2);

const float Ts_yaw = 1.0;
const float os_yaw = 2.0/100;

const float zeta_yaw = abs(log(os_yaw))/(sqrt(pow(log(os_yaw),2)+pow(pi,2)));
const float omega_n_yaw = 4.0/(zeta_yaw*Ts_yaw);

const float kd_y = 2.0*zeta_yaw*omega_n_yaw; // kd e kp para yaw
const float kp_y = pow(omega_n_yaw,2);

// Verticl Estimator
const float estimator_vertical_dt = 2.5e-2;
const float estimator_vertical_wc = 10;
const float estimator_vertical_zeta = sqrt(2)/2;

const float EV_l1 = pow(estimator_vertical_wc, 2);
const float EV_l2 = 2*estimator_vertical_zeta*estimator_vertical_wc;
#endif