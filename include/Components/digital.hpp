#ifndef DIGITAL_HPP_
#define DIGITAL_HPP_

#include "../general.hpp"

class DigitalDevice
{
    private:
        uint_8 pin;
        string name;

    public:
        DigitalDevice(string Name, uint_8 Pin)
        {
            pin = Pin;
            name = Name;
        }

        ~DigitalDevice()
        {
            name = "";
            pin = 0;
        }

        // 
};

#endif