#ifndef PESEL_H
#define PESEL_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

class pesel{
    public:

    pesel();

    short PESEL[11];
    bool valid = 0;

    int getBirthYear();
    int getBirthMonth();
    int getBirthDay();
    const char* getSex();
    int checkSum();
    int checkMonth();
    int checkDay();
    int leapYear(int);
    void PeselValidator(char*);

    virtual ~pesel();
};

#endif // PESEL_H
