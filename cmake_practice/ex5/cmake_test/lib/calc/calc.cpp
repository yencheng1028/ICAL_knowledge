#include"calc.h"
Calc::Calc()
:serial(5,"/dev/ACM0")
{

}
void Calc::GetX(int x)
{
    cal_x_=x;
}

int Calc::Cube()
{
    return cal_x_*cal_x_*cal_x_;
}

int Calc::Square()
{
    return cal_x_*cal_x_;
}
