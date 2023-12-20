#include <iostream>
#include "../include/lib.hpp"

Person::Person(int age,std::string name)
{
    this->age=age;
    this->name=name;
}

void Person::hello(void)
{
    std::cout<<"hello world"<<std::endl;
}

void Person::introduce(void)
{
    std::cout<<"my name is "<<this->name<<std::endl;
}

void Person::how_old(void)
{
    std::cout<<"I'm "<<this->age<<" years old"<<std::endl;
}