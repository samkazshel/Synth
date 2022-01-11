#include <iostream>
using namespace std;

#include "olcNoiseMaker.h"

int main()
{

    wcout << "synth" << endl;

    vector<wstring> devices = olcNoiseMaker<short>::Enumerate();

    for (auto d : devices)
        wcout << "Found Output Device:" << d << endl;

    olcNoiseMaker<short> sound(devices[0], 44100, 1, 8, 512);

    return 0;
}