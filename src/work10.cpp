#include "../include/work10.hpp"
#include <iostream>
#include <iomanip>

double f(double t,double y)
{
    return y/(2*(t+1));
}

void run10()
{
    double y=1.0;
    double h=1;
    double t0=0.0;

    for(unsigned long long int i=0;i<=2;i++)
    {
        y=(y+h*(f((t0+i*h),y)));
        if (t0+i*h==1.0)
        {
            std::cout<<"t= "<<std::setprecision(15)<<t0+i*h
                <<" : y= "<<std::setprecision(15)<<y<<std::endl;
                std::cout<<"err= "<<std::setprecision(15)<<y-powf(2.0,0.5)<<std::endl;
        }
        if (t0+i*h==2.0)
        {
            std::cout<<"t= "<<std::setprecision(15)<<t0+i*h
                <<" : y= "<<std::setprecision(15)<<y<<std::endl;
                std::cout<<"err= "<<std::setprecision(15)<<y-powf(3.0,0.5)<<std::endl;
        }
    }
}