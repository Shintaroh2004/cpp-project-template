#include <iostream>
#include <Eigen/LU>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "../include/work8.hpp"

double Sigma(
    Eigen::Matrix<double,3,1> v_x,
    Eigen::Matrix<double,3,1> v_y,
    double pow_num_x,
    double pow_num_y
) {
    Eigen::Matrix<double,3,1> powed_vx=v_x;
    Eigen::Matrix<double,3,1> powed_vy=v_y;
    Eigen::Matrix<double,3,1> powed_vx2=powed_vx.unaryExpr([&](double value) {
        return pow(value,pow_num_x);
    });
    Eigen::Matrix<double,3,1> powed_vy2=powed_vy.unaryExpr([&](double value) {
        return pow(value,pow_num_y);
    });
    return (powed_vx2.array()*powed_vy2.array()).sum();
}

void run8(void)
{
    Eigen::Matrix<double,3,1> v_x;
    v_x << 2,3,5;
    Eigen::Matrix<double,3,1> v_y; 
    v_y << 2,4,6;

    Eigen::Matrix<double,2,2> XtX;
    XtX << Sigma(v_x,v_y,2.0,0.0),Sigma(v_x,v_y,1.0,0.0),
           Sigma(v_x,v_y,1.0,0.0),Sigma(v_x,v_y,0.0,0.0); 
    
    std::cout<<XtX<<std::endl;
    
    Eigen::Matrix<double,2,1> XtY;
    XtY << Sigma(v_x,v_y,1.0,1.0),Sigma(v_x,v_y,0.0,1.0);
    
    std::cout<<XtY<<std::endl;

    Eigen::Matrix<double,2,1> a;
    std::cout<<XtX.inverse()<<std::endl;
    a=XtX.inverse()*XtY;

    std::cout<<a<<std::endl;
}