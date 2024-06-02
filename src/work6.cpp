#include "../include/work6.hpp"
#include <Eigen/Core>
#include <Eigen/LU>
#include <iostream>

using namespace Eigen;

void run6_1()
{
    Matrix<double,3,3> A;
    Matrix<double,3,3> exA;

    A<<
    0,-3,2,
    1,-1,-2,
    4,1,-2;

    exA<<
    1,0,0,
    0,1,0,
    0,0,1;

    for (int i=0;i<3;i++)
    {
        std::cout<<"target"<<std::endl;
        std::cout<<"----------------------------------"<<std::endl;
        std::cout<<A.block(i,i,3-i,3-i)<<std::endl;
        std::cout<<"----------------------------------"<<std::endl;

        int maxID;
        A.block(i,i,3-i,3-i).col(0).cwiseAbs().maxCoeff(&maxID);
        std::cout<<"----------------------------------"<<std::endl;
        std::cout<<"max col is "<<maxID+i<<std::endl;
        Vector3d remain=A.row(i);
        A.row(i)=A.row(maxID+i);
        A.row(maxID+i)=remain;
        Vector3d ex_remain=exA.row(i);
        exA.row(i)=exA.row(maxID+i);
        exA.row(maxID+i)=ex_remain;
        std::cout<<"A is\n"<<A<<std::endl;
        std::cout<<"exA is\n"<<exA<<std::endl;
        std::cout<<"----------------------------------"<<std::endl;

        for(int j=2;j>i;j--)
        {
            exA.row(j)-=exA.row(i)*(A(j,i)/A(i,i));
            A.row(j)-=A.row(i)*(A(j,i)/A(i,i));

            std::cout<<"----------------------------------"<<std::endl;
            std::cout<<"A is\n"<<A<<std::endl;
            std::cout<<"exA is\n"<<exA<<std::endl;
            std::cout<<"----------------------------------"<<std::endl;
        }
        for(int z=0;z<i;z++)
        {
            exA.row(z)-=exA.row(i)*(A(z,i)/A(i,i));
            A.row(z)-=A.row(i)*(A(z,i)/A(i,i));

            std::cout<<"----------------------------------"<<std::endl;
            std::cout<<"A is\n"<<A<<std::endl;
            std::cout<<"exA is\n"<<exA<<std::endl;
            std::cout<<"----------------------------------"<<std::endl;
        }

        exA.row(i)/=A(i,i);     
        A.row(i)/=A(i,i);

        std::cout<<"----------------------------------"<<std::endl;
        std::cout<<"A is\n"<<A<<std::endl;
        std::cout<<"exA is\n"<<exA<<std::endl;
        std::cout<<"----------------------------------"<<std::endl;     
    }
    std::cout<<"ans:"<<std::endl;
    std::cout<<"A is\n"<<A<<std::endl;
    std::cout<<"exA is\n"<<exA<<std::endl;
}

void run6_2()
{
    Matrix<double,3,3> A;
    Vector3d b;
    Vector3d xi_1;
    Vector3d xi_2;
    A<<
    4,1,2,
    0,2,-1,
    -1,1,3;

    b<<-4,-5,2;

    xi_1<<0,0,0;

    for(int i=0;i<3;i++)
    {
        std::cout<<i<<"回目"<<std::endl;
        std::cout<<xi_1<<std::endl;

        xi_2(0)=(b(0)-(A(0,1)*xi_1(1))-A(0,2)*xi_1(2))/A(0,0);
        xi_2(1)=(b(1)-(A(1,0)*xi_1(0))-A(1,2)*xi_1(2))/A(1,1);
        xi_2(2)=(b(2)-(A(2,0)*xi_1(0))-A(2,1)*xi_1(1))/A(2,2);

        xi_1=xi_2;
    }
}

void run6_3()
{
    Matrix<double,3,3> A;
    Vector3d b;
    Vector3d xi_1;
    A<<
    4,1,2,
    0,2,-1,
    -1,1,3;

    b<<-4,-5,2;

    xi_1<<0,0,0;

    for(int i=0;i<3;i++)
    {
        std::cout<<i<<"回目"<<std::endl;
        std::cout<<xi_1<<std::endl;
        
        xi_1(0)=(b(0)-(A(0,1)*xi_1(1))-A(0,2)*xi_1(2))/A(0,0);
        xi_1(1)=(b(1)-(A(1,0)*xi_1(0))-A(1,2)*xi_1(2))/A(1,1);
        xi_1(2)=(b(2)-(A(2,0)*xi_1(0))-A(2,1)*xi_1(1))/A(2,2);
    }
}