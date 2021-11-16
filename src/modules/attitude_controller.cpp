#include "attitude_controller.h"
// #include "attitude_estimator.h"

// Class constructor
AttitudeController :: AttitudeController ()
{
    tau_phi = 0;
    tau_psi = 0;
    tau_theta = 0;
}

// Control torques (N.m) given reference angles ( rad) and current angles ( rad ) and angular velocities ( rad /s)
void AttitudeController :: control(float phi_r, float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r)
{

    // control_siso(float angle_r, float angle, float rate, float kp, float kd)
    float acc_phi_r = control_siso(phi_r, phi, p, kp_rp, kd_rp);
    float acc_theta_r = control_siso(theta_r, theta, q, kp_rp, kd_rp);
    float acc_psi_r = control_siso(psi_r, psi, r, kp_y, kd_y);

    tau_phi = I_xx*acc_phi_r;
    tau_theta = I_yy*acc_theta_r;
    tau_psi = I_zz*acc_phi_r;

}

// Control torque (N.m) given reference angle ( rad ) and current angle ( rad ) and angular velocity ( rad /s) with given controller gains
float AttitudeController :: control_siso(float angle_r, float angle, float rate, float kp, float kd)
{
    float phi_r_pp = kp*(angle_r-angle) + kd*(0 - rate);
    return phi_r_pp;
}

