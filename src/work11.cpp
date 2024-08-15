#include "../include/work11.hpp"
#include <iostream>

using namespace std;

double f(double t,double y)
{
    return y/(2*(t+1));
}

void run11_1()
{
    double y=1.0;
    double t=0.0;
    double h=1.0;

    double a=1.0;
    double b=1.0;
    double w1=1.0/2.0;
    double w2=1.0/2.0;

    for (double i=0.0;i<2.0;i+=1.0)
    {
        double k1=f(t,y);
        cout<<"k1="<<k1<<endl;
        double k2=f(t+(a*h),y+b*h*k1);
        cout<<"k2="<<k2<<endl;
        y=y+(w1*k1+w2*k2)*h;
        cout<<"y("<<i+1<<")="<<y<<endl;
        t += h;
    }
}

void run11_2()
{
    double y=1.0;
    double t=0.0;
    double h=1.0;

    double a=1.0/2.0;
    double b=1.0/2.0;
    double w1=0.0;
    double w2=1.0;

    for (double i=0.0;i<2.0;i+=1.0)
    {
        double k1=f(t,y);
        cout<<"k1="<<k1<<endl;
        double k2=f(t+(a*h),y+b*h*k1);
        cout<<"k2="<<k2<<endl;
        y=y+(w1*k1+w2*k2)*h;
        cout<<"y("<<i+1<<")="<<y<<endl;
        t += h;
    }
}

void run11_3()
{
    double y = 1.0;
    double t = 0.0;
    double h = 1.0;

    double limit = 2.0 / h;

    for (double i = 0.0; i < limit; i += 1.0)
    {
        double k1 = f(t, y);
        cout << "k1=" << k1 << endl;
        double k2 = f(t + (h / 2.0), y + (h / 2.0) * k1);
        cout << "k2=" << k2 << endl;
        double k3 = f(t + (h / 2.0), y + (h / 2.0) * k2);
        cout << "k3=" << k3 << endl;
        double k4 = f(t + h, y + h * k3);
        cout << "k4=" << k4 << endl;

        y = y + h * (k1 + (2 * k2) + (2 * k3) + k4) / 6;
        cout << "y(" << i+1 << ")=" << y << endl;

        t += h;
    }
}