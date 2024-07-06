#include <iostream>
#include <stdio.h>
#include <vector>
#include "../include/work7.hpp"

typedef std::vector<std::vector<double>> P;

double z(double x,P p,int i)
{
    printf("%0.1f ",p[i][1]);
    double pi=1;
    for(int j=0;j<4;j++)
    {
        if(j!=i)
        {
            pi*=(x-(p[j][0]))/((p[i][0])-(p[j][0]));
            printf("* (%0.1f-%0.1f)/(%0.1f-%0.1f) ",x,p[j][0],p[i][0],p[j][0]);
        }
    }
    double ans=(p[i][1])*pi;

    printf(" = %f\n",ans);

    return pi;
}

void run7_1()
{
    P p = {
        {-1.0,3.0},
        {0.0,1.0},
        {1.0,1.0},
        {2.0,9.0}
    };

    double sum=0;

    for(int i=0;i<4;i++)
    {
        sum+=(p[i][1])*z(1.5,p,i);
    }

    std::cout<<sum<<std::endl;
}