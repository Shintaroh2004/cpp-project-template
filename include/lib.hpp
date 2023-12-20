#include <iostream>

class Person
{
    private:
        int age;
        std::string name;

    public:
        Person(int age,std::string name);
        void hello(void);
        void introduce(void);
        void how_old(void);
};