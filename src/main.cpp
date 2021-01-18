#pragma once
#include "../include/PID/pid.hpp"
#include <stdio.h>

using namespace std;

double f(double t)
{
    return 2.0 * t;
}

int main()
{
    // system variables
    double dtime = 0.25f;
    double j = 0.0f;

    // PID Controller Values
    double kp = 0;
    double ki = 0;
    double kd = 0;
    double target_value = 20;

    PIDC * pid_controller = new PIDC(kp, ki, kd, target_value);

    printf("PID Values:\nKP: %f\nKI: %f\nKD:%f\nTarget Value: %f\n\n", pid_controller->getKP(), pid_controller->getKI(), pid_controller->getKD(), pid_controller->getTarget());

    for (double i = 0.0f; i <= 60.0f; i += dtime)
    {
        printf("Current Time: %f\n", i);
        if (i > 0.0f)
        {
            printf("Output Value: %0.2f\n", pid_controller->PID(f(i), f(j), i, j) + f(i));
        }
        
        else
        {
            printf("Output Value: %0.2f\n", f(i));
        }
        j = i;
    }

    return 0;
}
