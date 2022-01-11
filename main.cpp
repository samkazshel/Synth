#include <iostream>
using namespace std;

#include "olcNoiseMaker.h"

double MakeNoise(double dTime)
{
    return 0.5 * sin(440.0 * 2 * 3.14159 * dTime);
}

int main()
{

    wcout << "synth" << endl;

    //going through an enumerating sound hardware
    vector<wstring> devices = olcNoiseMaker<short>::Enumerate();

    //displaying findings
    for (auto d : devices)
        wcout << "Found Output Device:" << d << endl;

    //create sound machine
    olcNoiseMaker<short> sound(devices[0], 44100, 1, 8, 512);

    //linking noise maker to sound machine
    sound.SetUserFunction(MakeNoise);

    return 0;

    while (1)
    {
    }
}
