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
const float kd_rp = 1; //kd e kp para roll e pitch
const float kp_rp = 1;

const float kd_y = 0.5; // kd e kp para yaw
const float kp_y = 0.5;
#endif