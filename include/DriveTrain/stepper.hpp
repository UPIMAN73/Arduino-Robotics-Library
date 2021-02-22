#ifndef STEPPER_HPP_
#define STEPPER_HPP_

#include "motor.hpp"

class StepperMotor : public Motor
{
    private:
        // stepper motor mechanics
        uint_16 steps;
        uint_32 rpm;

        // Additional pins for stepper motor
        uint_8 pin2;
        uint_8 pin3;
        uint_8 pin4;

        // Stepper Motor Class
        // Stepper stepper;

    public:
        StepperMotor(string Name, uint_8 Pin, uint_8 Pin2, uint_16 Steps, uint_32 RPM) : Motor(Name, Pin)
        {
            // required settings of motor
            steps = Steps;
            rpm = RPM;

            // Pins for motor
            pin2 = Pin2;
        }

        StepperMotor(string Name, uint_8 Pin, uint_8 Pin2, uint_8 Pin3, uint_8 Pin4, uint_16 Steps, uint_32 RPM) : Motor(Name, Pin)
        {
            // required settings of motor
            steps = Steps;
            rpm = RPM;

            // Pins for motor
            pin2 = Pin2;
            pin3 = Pin3;
            pin4 = Pin4;
        }

        ~StepperMotor()
        {
            setName("");
            setPin(0);
            pin2 = 0;
            pin3 = 0;
            pin4 = 0;
            steps = 0;
            rpm = 0;
        }

        uint_16 getSteps()
        {
            return steps;
        }

        void setSteps(uint_16 Steps)
        {
            steps = Steps;
        }

        void init()
        {
            // stepper = new Stepper(steps, Pin, Pin2, Pin3, Pin4);
            // stepper.setSpeed(rpm);
        }

        void set(int steps)
        {
            while (steps != 0 && !EMS_MODE)
            {
                if (steps > 0)
                {
                    // stepper.step(1);
                    steps--;
                }
                else
                {
                    // stepper.step(-1);
                    steps++;
                }
            }
        }

        void stop()
        {
            // stepper.step(0);
        }

        void teleOp(bool inverted)
        {
            if (inverted)
            {
                // stepper.step(-1);
            }
            else
            {
                // stepper.step(1);
            }
        }
};


#endif