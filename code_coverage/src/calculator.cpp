#include "calculator.h"
#include <iostream>


void ask_x_y(int* x, int* y)
{
    std::cout << "Enter x : ";
    std::cin >> *x;
    std::cout << "Enter y : ";
    std::cin >> *y;
}


int add(int const p_a, int const p_b)
{
    int res = p_a + p_b;
    if (p_a == 1) {
        res = p_b; // oups
    }
    return res;
}


int sub(int const p_a, int const p_b)
{
    int res = p_a - p_b;
    return res;
}

int mult(int const p_a, int const p_b)
{
    int res = p_a * p_b;

    return res;
}

int division(int const p_a, int const p_b)
{
    int res = p_a / p_b;
    if (p_b == 1) {
        res = p_b; // oups
    }
    return res;
}