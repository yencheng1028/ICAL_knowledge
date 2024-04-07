#include <iostream>
#include <vector>

// This chapter basically says why the meowing god on Earth my variable changes when passing through function

void pass_by_value(int x)
{
    x += 1;
}

void pass_by_pointer(int *x)
{
    (*x) += 1;
}

void pass_by_reference(int &x)
{
    x += 1;
}

void swap_by_value(int a, int b) // this does not do swap
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_by_pointer(int *a, int *b) // not recommended in c++, but you will use it in the next semester
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_by_reference(int &a, int &b) // recommentded
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 0;
    int *x_address = &x;
    int &x_reference = x;

    // pass_by_value(x);
    // pass_by_pointer(&x);
    pass_by_reference(x);

    std::cout << "value of x: " << x << "\n";

    int a = 3, b = 5;

    // swap_by_value(a, b);
    // swap_by_pointer(&a, &b);
    swap_by_reference(a, b);

    std::cout << "a: " << a << "b: " << b << "\n";
}