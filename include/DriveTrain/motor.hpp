#ifndef MOTOR_HPP
#define MOTOR_HPP
#pragma once
#include "../general.hpp"


class Motor
{
    private:
        string name;
        uint_8 pin;

    public:
        Motor(string Name, uint_8 Pin)
        {
            name = Name;
            pin = Pin;
        }

        ~Motor()
        {
            // Remove all member variable values
            name = "";
            pin = 0;
        }

        string getName()
        {
            return name;
        }

        const char * printName()
        {
            return name.c_str();
        }

        uint_8 getPin()
        {
            return pin;
        }

        void setName(string Name)
        {
            name = Name;
        }

        void setPin(uint_8 Pin)
        {
            pin = Pin;
        }

        // 
        void init()
        {
            // Import library options and setup motor environment
        }

        // 
        void set(int val)
        {
            // Get motor to specific value
        }

        // 
        void stop()
        {
            // Turn Motor Off
        }

        //
        void teleOp()
        {
            // TeleOperation controll motor movement
        }
};

#endif