#include <iostream>
#include <math.h>
#include <Eigen/Core>
#include <Eigen/LU>
#include <Eigen/Dense>
#include "../include/work5.hpp"

using namespace Eigen;

//----------------------------------------------
//     3x_2+2x_3=4
//x_1 -x_2-2x_3=5
//4x_1+x_2-2x_3=4
//----------------------------------------------

void run5_1()
{
    Matrix<double,3,3> A;
    A<<
        0.0,-3.0,2.0,
        1.0,-1.0,-2.0,
        4.0,1.0,-2.0;
    Matrix<double,3,1> x;
    x<<
        4.0,
        5.0,
        4.0;
        
    for(int i=0;i<3;i++)
    {
        std::cout<<"--------------------"<<std::endl;
        std::cout<<"target is\n"<<A.block(i,i,3-i,3-i)<<std::endl;
        VectorXf::Index maxId;
        A.block(i,i,3-i,3-i).col(0).cwiseAbs().maxCoeff(&maxId);

        Vector3d remain_vec=A.row(i);
        A.row(i)=A.row(maxId+i);
        A.row(maxId+i)=remain_vec;

        double remain=x(i);
        x(i)=x(maxId+i);
        x(maxId+i)=remain;

        std::cout<<"--------------------"<<std::endl;
        std::cout<<"max row is:"<<maxId+i<<std::endl;
        std::cout<<A<<std::endl;
        std::cout<<x<<std::endl;
        std::cout<<"--------------------"<<std::endl;

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

void run5_2()
{
    Matrix<double,3,3> A;
    A<<
        0.0,-3.0,2.0,
        1.0,-1.0,-2.0,
        4.0,1.0,-2.0;
    Matrix<double,3,1> x;
    x<<
        4.0,
        5.0,
        4.0;

    for(int i=0;i<3;i++)
    {
        std::cout<<"--------------------"<<std::endl;
        std::cout<<"target is\n"<<A.block(i,i,3-i,3-i)<<std::endl;
        VectorXf::Index maxId;
        A.block(i,i,3-i,3-i).col(0).cwiseAbs().maxCoeff(&maxId);

        Vector3d remain_vec=A.row(i);
        A.row(i)=A.row(maxId+i);
        A.row(maxId+i)=remain_vec;

        double remain=x(i);
        x(i)=x(maxId+i);
        x(maxId+i)=remain;

        std::cout<<"--------------------"<<std::endl;
        std::cout<<"max row is:"<<maxId+i<<std::endl;
        std::cout<<A<<std::endl;
        std::cout<<x<<std::endl;
        std::cout<<"--------------------"<<std::endl;

        for(int j=2;j>i;j--){
            x.row(j)-=x.row(i)*(A(j,i)/A(i,i));
            A.row(j)-=A.row(i)*(A(j,i)/A(i,i));
            std::cout<<A<<std::endl;
            std::cout<<x<<std::endl;
        }
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
