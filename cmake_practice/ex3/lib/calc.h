#ifndef __CALC_H__
#define __CALC_H__

#include<iostream>
#include<cstdlib>
using namespace std;

class Calc
{
    public:
        int Cube();
        int Square();
        void GetX(int x);
    private:
        int cal_x_;

};

#endif
