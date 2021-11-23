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

// Attitude Estimator - Lab 07 parameters
const float dt = 2e-3; // 500 Hz

const float wc_roll = 1;
const float alpha_roll = 1 - wc_roll*dt/(1+wc_roll*dt);

const float wc_pitch = 5;
const float alpha_pitch = 1 - wc_pitch*dt/(1+wc_pitch*dt);

// Attitude controller - Lab 08
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

// Vertical Estimator - Lab 09

const float dt_range = 1.0/20;
const float vertical_estimator_wc = 10;
const float vertical_estimator_zeta = sqrt(2)/2;

const float l1 = pow(vertical_estimator_wc, 2);
const float l2 = 2*vertical_estimator_zeta*vertical_estimator_wc;

// Vertical Controller - Lab 10
const float Ts_vertical = 0.6;
const float os_vertical = 0.8/100;

const float zeta_vertical = abs(log(os_vertical))/(sqrt(pow(log(os_vertical),2)+pow(pi,2)));
const float omega_n_vertical = 4/(zeta_vertical*Ts);

const float kd_vertical = 2*zeta_vertical*omega_n_vertical; //kd e kp para roll e pitch
const float kp_vertical = pow(omega_n_vertical,2);

// Horizontal Estimator - Lab 11
const double gamma = 42*pi/180; // rad --> ângulo de visão
const double W = 420; // pixels --> resolução do sensor
const float sigma = (2.0*tan(gamma/2))/(W*dt);
const float l_hor = 50.0;
#endif