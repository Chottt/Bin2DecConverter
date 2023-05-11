// BinaryCalTool.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <cmath>

// for test I don't know that work. Hahaa


using namespace std;

struct DataBin
{
    int dataBinary[64];
};

DataBin BinaryCalculate(long long number)
{
    long long filter = 1;
    DataBin dataBinary;

    for (int i = 0; i < (sizeof(number) * 8); ++i)
    {
        if (number & (filter << i))
        {
            dataBinary.dataBinary[i] = 1;
        }
        else
        {
            dataBinary.dataBinary[i] = 0;
        }
    }
    return dataBinary;
}

int main()
{
    double number = 200.12345; // Enter your digit for convert
    int bin2dec = 0;

    long long* Ptr = (long long*) (&number);

    auto dataBinary = BinaryCalculate(*Ptr);

    cout << endl;
    cout << "Your digit: " << number << endl;

    cout << "Binary: " << endl;
    for (int i = 0; i < (sizeof(double) * 8); ++i)
    {
        bin2dec += ((dataBinary.dataBinary[i]) * pow(2, (i)));
    }

    cout << endl;
    cout << bin2dec;
    return 0;
}
