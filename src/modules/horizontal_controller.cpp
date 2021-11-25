#include "horizontal_controller.h"

// Class constructor
HorizontalController :: HorizontalController ()
{

}

// Control reference roll and pitch angles (rad) given reference positions (m) and current positions (m) and velocities (m/s)
void HorizontalController :: control (float x_r, float y_r, float x, float y, float u, float v)
{

}

// Control acceleration given reference position (m) and current position (m) and velocity (m/s) with given controller gains
float HorizontalController :: control_siso ( float pos_r , float pos , float vel , float kp , float kd)
{

}
