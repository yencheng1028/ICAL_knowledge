#ifndef __CALC_H__
#define __CALC_H__

#include<iostream>
#include<cstdlib>
#include<serial.hpp>
using namespace std;

class Calc
{
    public:
        Calc();
        int Cube();
        int Square();
        void GetX(int x);
    private:
        int cal_x_;
        SERIAL serial;

};

#endif
