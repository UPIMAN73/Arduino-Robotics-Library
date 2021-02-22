#ifndef MOTORLIST_HPP
#define MOTORLIST_HPP

#include "motor.hpp"

class MotorList
{
    private:
        Motor * array;
        uint_8 size = 0;

    public:
        MotorList(uint_8 Size)
        {
            size = Size;
            Motor *Arr[size];
            for (uint_8 i = 0; i < size; i++)
            {
                Arr[i] = new Motor("", 0);
            }
            array = *Arr;
        }

        ~MotorList()
        {
            for (uint_8 i = 0; i < size; i++)
            {
                delete &array[i];
            }
            size = 0;
        }

        void assignMotor(uint_8 id, Motor * m)
        {
            if (id < size)
            {
                array[id] = *m;
            }
        }

        // Motor index in motor list
        Motor * getIndex(uint_8 val)
        {
            if (val < size)
            {
                return &array[val];
            }

            else
            {
                return nullptr;
            }
        }

        // Turn motor values
        void setAllMotors(int val)
        {
            for (uint_8 i = 0; i < size; i++)
            {
                array[i].set(val);
            }
        }

        void setMotor(uint_8 id, int val)
        {
            if (id < size)
            {
                array[id].set(val);
            }
            else
            {
                // Report error with ID
                return;
            }
        }

        // Emergency Shutdown
        void EMS()
        {
            for (uint_8 i = 0; i < size; i++)
            {
                array[i].stop();
            }
        }

        // Stop All motors using EMS function
        void stopAllMotors()
        {
            EMS();
        }

        // Maybe id range set
};



#endif