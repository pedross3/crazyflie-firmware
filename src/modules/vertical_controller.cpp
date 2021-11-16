#include "vertical_controller.h"

// Class constructor
VerticalController:: VerticalController()
{
    f_t = 0;
}

// Control torques (N.m) given reference angles ( rad) and current angles ( rad ) and angular velocities ( rad /s)
void VerticalController :: control(float z_r, float z, float w)
{
    float z_r_pp = control_siso(z_r, z, w, kp_vertical, kd_vertical);
    f_t = m*(g + z_r_pp);

}

// Control torque (N.m) given reference angle ( rad ) and current angle ( rad ) and angular velocity ( rad /s) with given controller gains
float VerticalController :: control_siso(float pos_r, float pos, float vel,         float kp, float kd)
{
    float z_r_pp = kp*(pos_r-pos) + kd*(0 - vel);
    return z_r_pp;
}
