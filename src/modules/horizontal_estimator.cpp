#include "horizontal_estimator.h"

// Class constructor
HorizontalEstimator :: HorizontalEstimator() : flow (PA_7, PA_6, PA_5, PB_4)
{
    x = 0;
    y = 0;
    u = 0;
    v = 0;
}

// Initialize class
void HorizontalEstimator :: init ()
{
    flow.init();

}

// Predict horizontal positions and velocities from model
void HorizontalEstimator :: predict(float phi, float theta)
{
    float a = 0;
}

// Correct horizontal velocities with measurements
void HorizontalEstimator :: correct(float phi, float theta, float p, float q, float z)
{
    float a = 0;
}
