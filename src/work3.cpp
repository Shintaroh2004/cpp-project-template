#include <iostream>
#include <iomanip>
#include <math.h>
#include "../include/work3.hpp"

double f1(double x){
    return pow(x,2)-2;
}

double f1_1(double x){
    return 2*x;
}

double f2(double x){
    return pow(x,2)-1-sin(x);
}

double f2_1(double x){
    return 2*x-cos(x);
}

double f2_2(double x){
    return 2+sin(x);
}

double newton(double x){
    return x-(f1(x)/f1_1(x));
}

double secant(double x1,double x2){
    return x2-((x2-x1)/(f1(x2)-f1(x1))*f1(x2));
}

double bailey(double x){
    return x-f2(x)/(f2_1(x)-((f2(x)*f2_2(x))/(2*f2_1(x))));
}

void run3_1(){
    double x=2.0;
    for(int i=0;i<3;i++){
        std::cout<<"(x, f(x), f'(x))="<<x<<","<<f1(x)<<","<<f1_1(x)<<std::endl;
        x=newton(x);
    }
}

void run3_2(){
    double xr;
    double x1=2.5;
    double x2=2.0;
    double x3;

    std::cout<<"(x, f(x))="<<x1<<","<<f1(x1)<<std::endl;
    x3=secant(x1,x2);
    xr=x1;
    x1=x2;
    x2=x3;

    for(int i=0;i<3;i++){
        std::cout<<"(x, f(x), f'(x))="<<x1<<","<<f1(x1)<<","<<(f1(x1)-f1(xr))/(x1-xr)<<std::endl;
        x3=secant(x1,x2);
        xr=x1;
        x1=x2;
        x2=x3;
    }
}

void run3_3(){
    double x=3.0;
    for(int i=0;i<3;i++){
        std::cout<<"(x, f(x), f'(x), f''(x))=";
        std::cout<<std::fixed << std::setprecision(7)<<x<<",";
        std::cout<<std::fixed << std::setprecision(7)<<f2(x)<<",";
        std::cout<<std::fixed << std::setprecision(7)<<f2_1(x)<<",";
        std::cout<<std::fixed << std::setprecision(7)<<f2_2(x)<<std::endl;
        x=bailey(x);
    }
}