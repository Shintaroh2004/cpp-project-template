#include <iostream>
#include <math.h>
#include <../include/work2.hpp>

double f(double x)
{
    return x*x-2;
}

double g(double a,double b)
{
    return (a*f(b)-b*f(a))/(f(b)-f(a));
}

void run2_1()
{
    double a=0.0;
    double b=2.0;

    for(int i=0;i<5;i++)
    {
        double c=g(a,b);
        //double c=(a+b)/2;
        std::cout<<a<<" "<<b<<" "<<c<<" "<<f(a)<<" "<<f(c)<<" "<<f(a)*f(c)<<std::endl;

        if (f(a)*f(c)<0.0)
        {
            b=c;
        }
        else if (f(a)*f(c)>=0.0)
        {
            a=c;
        }
    }
}

double h(double x)
{
    return -sin(x);
}

double g2(double x,double y)
{
    return x-cos(y);
}

void run2_2()
{
    double xa=0.0;
    double xb=2.0;

    for(int i=0;i<5;i++)
    {
        double ya=h(xa);
        double yb=h(xb);

        double xc=(xa+xb)/2.0;
        double yc=h(xc);

        std::cout<<xa<<" "<<xb<<" "<<ya<<" "<<yb<<" "<<xc<<" "<<yc<<" "<<abs(xb-xa)<<" "<<g2(xa,ya)<<" "<<g2(xc,yc)<<" "<<g2(xa,ya)*g2(xc,yc)<<std::endl;

        if (g2(xa,ya)*g2(xc,yc)<0.0)
        {
            xb=xc;
        }
        else if (g2(xa,ya)*g2(xc,yc)>=0.0)
        {
            xa=xc;
        }
    }
}
