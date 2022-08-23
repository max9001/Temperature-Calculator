//my_oop_temperature.h

#ifndef MY_OOP_TEMPERATURE
#define MY_OOP_TEMPERATURE

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Temperature {
    private: 
        double tempValue;
        char tempType;
    public:
        string tempOutput;

        //-------------------------------
        // Default Constructor
        //-------------------------------

        Temperature(){
            tempValue = 0;
            tempType = ' ';
            tempOutput = " ";
        }

        //-------------------------------
        // Constructor
        //-------------------------------

        Temperature(double tempValue, char tempType) {
            this->tempValue = tempValue;
            this->tempType = tempType;
            tempOutput = to_string(tempValue) + " " + tempType + "   ";
        }

        //-------------------------------
        // Destructor
        //-------------------------------

        ~Temperature() {}

        //-------------------------------
        // getF function
        // input:
        //      Temperature object
        // output:
        //      Temperature object (in farienheit)
        //-------------------------------
        
        Temperature getF(Temperature temperature){
            switch(toupper(temperature.tempType)){
                case 'F': {
                    Temperature tempF(temperature.tempValue, temperature.tempType);
                    return tempF;
                    break;
                }
                case 'C': {
                    Temperature tempF((temperature.tempValue * 9/5) + 32, 'F');
                    return tempF;
                    break;
                }
                case 'K': {
                    Temperature tempF(((temperature.tempValue - 273.15) * 9/5) + 32, 'F');
                    return tempF;
                    break;
                }
                default: {
                    Temperature error_temp(0, ' ');
                    return error_temp;
                }
            }
        }

        //-------------------------------
        // getC function
        // input:
        //      Temperature object
        // output:
        //      Temperature object (in celcius)
        //-------------------------------

        Temperature getC(Temperature temperature){
            switch(toupper(temperature.tempType)){
                case 'C': {
                    Temperature tempC(temperature.tempValue, temperature.tempType);
                    return tempC;
                    break;
                }
                case 'F': {
                    Temperature tempC((temperature.tempValue - 32) * 5/9, 'C');
                    return tempC;
                    break;
                }
                case 'K': {
                    Temperature tempC((temperature.tempValue - 273.15), 'C');
                    return tempC;
                    break;
                }
                default: {
                    Temperature error_temp(0, ' ');
                    return error_temp;
                }
            }
        }

        //-------------------------------
        // getK function
        // input:
        //      Temperature object
        // output:
        //      Temperature object (in kelvin)
        //-------------------------------

        Temperature getK(Temperature temperature){
            switch(toupper(temperature.tempType)){
                case 'K': {
                    Temperature tempK(temperature.tempValue, temperature.tempType);
                    return tempK;
                    break;
                }
                case 'F': {
                    Temperature tempK(((temperature.tempValue - 32) * 5/9) + 273.15, 'K');
                    return tempK;
                    break;
                }
                case 'C': {
                    Temperature tempK((temperature.tempValue + 273.15), 'K');
                    return tempK;
                    break;
                }
                default: {
                    Temperature error_temp(0, ' ');
                    return error_temp;
                }
            }
        }
};

#endif