#ifndef ANALOG_HPP_
#define ANALOG_HPP_

#include "../general.hpp"

class AnalogDevice
{
    private:
        uint_8 pin;
        string name;

    public:
        AnalogDevice(string Name, uint_8 Pin)
        {
            pin = Pin;
            name = Name;
        }

        ~AnalogDevice()
        {
            name = "";
            pin = 0;
        }

        // 
};

#endif