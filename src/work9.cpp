#include <iostream>
#include "../include/work9.hpp"

double f(double x)
{
    return 1/x;
}

void run9_1()
{
    double x_min=1.0;
    double x_max=5.0;
    int n=4;
    double h=(x_max-x_min)/static_cast<double>(n);

    double S=0.0;

    for (int i=0;i<n;i++)
    {
        std::cout<<h*f(x_min+h*i)<<std::endl;
        S+=h*f(x_min+h*i);
    }

    std::cout<<S<<std::endl;    
}

void run9_2()
{
    double x_min=1.0;
    double x_max=5.0;
    int n=4;
    double h=(x_max-x_min)/static_cast<double>(n);

    double S=0.0;

    for (int i=0;i<n;i++)
    {
        std::cout<<h*f(x_min+h*(i+1))<<std::endl;
        S+=h*f(x_min+h*(i+1));
    }

    std::cout<<S<<std::endl;    
}

void run9_3()
{
    double x_min=1.0;
    double x_max=5.0;
    int n=4;
    double h=(x_max-x_min)/static_cast<double>(n);

    double S=0.0;

    for (int i=0;i<n;i++)
    {
        std::cout<<h*f(x_min+h*(i)+static_cast<double>(h/2))<<std::endl;
        S+=h*f(x_min+h*(i)+static_cast<double>(h/2));
    }

    std::cout<<S<<std::endl;    
}

void run9_4()
{
    double x_min=1.0;
    double x_max=5.0;
    int n=4;
    double h=(x_max-x_min)/static_cast<double>(n);

    double S=0.0;

    for (int i=0;i<n;i++)
    {
        std::cout<<(h/2.0)*(f(x_min+h*(i))+f(x_min+h*(i+1)))<<std::endl;
        S+=(h/2.0)*(f(x_min+h*(i))+f(x_min+h*(i+1)));
    }

    std::cout<<S<<std::endl;    
}

void run9_5()
{
    double x_min=1.0;
    double x_max=5.0;
    int n=4;
    double h=(x_max-x_min)/static_cast<double>(n);

    double S=0.0;

    for (int i=0;i<n;i+=2)
    {
        std::cout<<(h/3.0)*(f(x_min+h*(i)) + 4*f(x_min+h*(i+1)) + f(x_min+h*(i+2)))<<std::endl;
        S+=(h/3.0)*(f(x_min+h*(i)) + 4*f(x_min+h*(i+1)) + f(x_min+h*(i+2)));
    }

    std::cout<<S<<std::endl;    
}