#include <iostream>
#include <memory>
#include "include/lib.hpp"

int main()
{
    std::shared_ptr<Person> taro= 
        std::shared_ptr<Person>(new Person(21,"hoge taro"));
    
    taro.get()->hello();
    taro.get()->introduce();
    taro.get()->how_old();

    return 0;
}