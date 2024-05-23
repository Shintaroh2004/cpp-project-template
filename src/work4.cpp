#include <Eigen/Core>
#include <Eigen/LU>
#include <iostream>

using namespace Eigen;

double f(Matrix<double,2,1>& xk)
{
    double x=xk(0,0);
    double y=xk(1,0);
    return sin(x)+y;
}

double g(Matrix<double,2,1>& xk)
{
    double x=xk(0,0);
    double y=xk(1,0);
    return x-cos(y);
}

double df_dx(Matrix<double,2,1>& xk)
{
    double x=xk(0,0);
    double y=xk(1,0);
    return cos(x);
}

double df_dy(Matrix<double,2,1>& xk)
{
    double x=xk(0,0);
    double y=xk(1,0);
    return 1.0;
}

double dg_dx(Matrix<double,2,1>& xk)
{
    double x=xk(0,0);
    double y=xk(1,0);
    return 1.0;
}
double dg_dy(Matrix<double,2,1>& xk)
{
    double x=xk(0,0);
    double y=xk(1,0);
    return sin(y);
}

void run4_1()
{
    // x2=1
    // y2=-1

    //x3=0.775685
    //y3=-0.720273
    Matrix<double,2,1> xk;
    Matrix<double,2,1> xkp1;

    xk<<0.0,
        0.0;
    
    for(int i=0;i<3;i++)
    {
        std::cout<<"loop"<<i+1<<"(x,y) = \n"<<xk<<std::endl;
        Matrix<double,2,2> A;
        Matrix<double,2,1> y_vec;
        A<<df_dx(xk),df_dy(xk),
            dg_dx(xk),dg_dy(xk);
        y_vec<<f(xk),g(xk);
        xkp1=xk-A.inverse()*y_vec;
        xk=xkp1;
    }

}

void run4_2()
{
    Matrix<double,3,3> A;
    A<<
        1.0,-1.0,-2.0,
        0.0,-3.0,2.0,
        4.0,1.0,-2.0;
    Matrix<double,3,1> x;
    x<<
        5.0,
        4.0,
        4.0;
    for(int i=0;i<(3-1);i++)
    {
        for(int j=2;j>i;j--){
            x.row(j)-=x.row(i)*(A(j,i)/A(i,i));
            A.row(j)-=A.row(i)*(A(j,i)/A(i,i));
            std::cout<<A<<std::endl;
            std::cout<<x<<std::endl;
        }
    }
    for(int i=2;i>0;i--)
    {
        for(int j=0;j<i;j++){
            x.row(j)-=x.row(i)*(A(j,i)/A(i,i));
            A.row(j)-=A.row(i)*(A(j,i)/A(i,i));
            std::cout<<A<<std::endl;
            std::cout<<x<<std::endl;
        }
    }
    for(int i=0;i<3;i++){
        x(i)/=A(i,i);
    }

    std::cout<<"ans:\n"<<x<<std::endl;
}