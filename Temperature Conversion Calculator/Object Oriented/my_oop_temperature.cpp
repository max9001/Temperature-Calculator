//my_oop_temperature.cpp

#include "my_oop_temperature.h"

int main(){
    double tempValue;
    char tempType;

    fstream temperatureFile("temperatures.txt", ios::in);
    fstream outFile("converted_temperatures.txt", ios::out);

    if (temperatureFile.fail()){
        cout << "File did not open\n";
        return 1;
    }
    
    while (true){
        temperatureFile >> tempValue >> tempType;
        if(temperatureFile.eof()){
            break;
        }
        Temperature temperature(tempValue, tempType);
        Temperature tempF = temperature.getF(temperature);
        Temperature tempC = temperature.getC(temperature);
        Temperature tempK = temperature.getK(temperature);
        outFile << tempF.tempOutput + tempC.tempOutput + tempK.tempOutput << endl;
    }
    return 0;
}