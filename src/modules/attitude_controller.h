# ifndef attitude_controller_h
# define attitude_controller_h

# include "mbed.h"
# include "crazyflie.h"

// Attitude controller class
class AttitudeController
{
    public :
        // Class constructor
        AttitudeController () ;
        // Control torques (.m) given reference angles (rad) and current angles (rad) and angular velocities (rad/s)
        void control (float phi_r, float theta_r, float psi_r, float phi, float theta, float psi, float p, float q, float r);
        // Torques (Nm)
        float tau_phi, tau_theta, tau_psi;
    private :
    // Control torque (Nm) given reference angle (rad) and current angle (rad) and angular velocity (rad/s) with given controller gains
    float control_siso (float angle_r, float angle, float rate, float kp, float kd);
};
# endif