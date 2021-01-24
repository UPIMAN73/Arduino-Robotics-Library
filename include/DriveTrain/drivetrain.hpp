#ifndef DRIVETRAIN_HPP
#define DRIVETRAIN_HPP

#include "motorlist.hpp"

class DriveTrain
{
    private:
        string name;
        MotorList * motor_list;

    public:
        DriveTrain(string n, MotorList * ml)
        {
            motor_list = ml;
            name = n;
        }

        ~DriveTrain()
        {
            // Remove all member variable values
            name = "";
            delete motor_list;
        }

        void move(int val);
        void moveMotor(uint_8 id, int val);
};

#endif