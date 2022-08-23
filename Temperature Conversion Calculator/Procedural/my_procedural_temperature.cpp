//my_procedural_temperature.cpp
#include "my_procedural_temperature.h"

int main() {
    double tempValue;
    char tempType;
    int lineCount = 0;
    string threeTempLine;

    fstream temperatureFile("temperatures.txt", ios::in);
    fstream outFile("converted_temperatures.txt", ios::out);

    if (temperatureFile.fail()){
        cout << "File did not open\n";
        return 1;
    }

    while (true){
        lineCount++;
        temperatureFile >> tempValue >> tempType;
        if(temperatureFile.eof()){
            break;
        }
        switch(toupper(tempType)){
            case 'F':
                threeTempLine = farienheitConvert(tempValue);
                outFile << threeTempLine << endl;
                break;
            case 'C':
                threeTempLine = celciusConvert(tempValue);
                outFile << threeTempLine << endl;
                break;
            case 'K':
                threeTempLine = kelvinConvert(tempValue);
                outFile << threeTempLine << endl;
                break;
            default:
                cout << "Error finding Temperature Type at line " << lineCount << endl;
        }
    }

    return 0;
}

string farienheitConvert(double tempValue){
    string line = to_string(tempValue) +" F   " + to_string((tempValue - 32)*5/9) + " C   " + to_string(((tempValue - 32)*5/9) + 273.15) + " K";
    return line;
}

string celciusConvert(double tempValue){
    string line = to_string(tempValue) +" C   " + to_string((tempValue*9/5) + 32) + " F   " + to_string(tempValue + 273.15) + " K";
    return line;
}

string kelvinConvert(double tempValue){
    string line = to_string(tempValue) +" K   " + to_string(((tempValue - 273.15)*9/5) + 32) + " F   " + to_string(tempValue - 273.15) + " C";
    return line;
}