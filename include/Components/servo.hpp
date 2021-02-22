#ifndef SERVO_HPP_
#define SERVO_HPP_

#include "../DriveTrain/motor.hpp"

class ServoMotor : public Motor
{
    protected:
        //  Any variables

    public:
        ServoMotor(string Name, uint_8 Pin) : Motor(Name, Pin)
        {
            // servo library constructor
        }

        ~ServoMotor()
        {
            setName("");
            setPin(0);            
        }

        // uint_8 getCurrentPosition()
        // {
        //     return servo.read();
        // }

        void set(uint_8 pos)
        {
            if (pos <= 180)
            {
                // servo.write(pos);
                // delay(10);
            }
        }

        void setPulse(uint_16 pulse)
        {
            // servo.writeMicroseconds(pulse);
            // delay(10);
        }


};

#endif