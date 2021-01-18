#ifndef PID_HPP
#define PID_HPP

/*
 * PID Controller
 * 
 * @author Joshua Calzadillas
 * 
 * @desc
 * This is a simple PID Controller that I made to be able to integrate this to any system.
 * All it needs is sensor data and the systematic values to then calculate the proper values
 * for a proper PID controlled system.
 * 
 * NOTE: You need to keep track of previous time and previous sensor/general values
 * NOTE: PID function already scales the target value with the pid calculated values
 */ 

class PIDC
{
    private:
        double target_value;
        double kp;
        double ki;
        double kd;

    public:
        PIDC(double kP, double kI, double kD, double tv)
        {
            kp = kP;
            ki = kI;
            kd = kD;
            target_value = tv;
        }

        ~PIDC()
        {
            kp, ki, kd, target_value = 0.0f;
        }

        /*
         * Setters
         */

        // Update PID Controller's kp value
        void setKP(double KP)
        {
            kp = KP;
        }

        // Update PID Controller's ki value
        void setKI(double KI)
        {
            ki = KI;
        }

        // Update PID Controller's kd value
        void setKD(double KD)
        {
            kd = KD;
        }

        // Update PID Controller's target value
        void setTarget(double tv)
        {
            target_value = tv;
        }


        /*
         * Getters
         */

        // Obtain PID Controller's kp value
        double getKP()
        {
            return kp;
        }

        // Obtain PID Controller's ki value
        double getKI()
        {
            return ki;
        }

        // Obtain PID Controller's kd value
        double getKD()
        {
            return kd;
        }

        // Obtain PID Controller's Target value
        double getTarget()
        {
            return target_value;
        }

        /*
         * Calculation Methods
         */

        // calculate error
        double error(double c_value)
        {
            return target_value - c_value;
        }

        // integral of function (Trapezoidal Rule)
        double inte(double c_value, double p_value, double p_time, double cur_time)
        {
            return 0.5 * (cur_time - p_time) * (c_value + p_value); 
        }

        // derivative of error values (f(yf)-f(yi)/dt)
        double der(double c_value, double p_value, double p_time, double cur_time)
        {
            return (c_value - p_value) / (cur_time - p_time);
        }

        // PID System calculation also integrates target value and current value
        double PID(double c_value, double p_value, double cur_time, double p_time)
        {
            return target_value * (kp * error(c_value) +
            ki * inte(c_value, p_value, p_time, cur_time) +
            kd * der(c_value, p_value, p_time, cur_time));
        }
};

#endif