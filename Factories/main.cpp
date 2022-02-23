#include "PersonFactory.hpp"
#include <iostream>

int main()
{
    PersonFactory prFactory;
    std::cout << prFactory.create_person("Name1") << std::endl;
    std::cout << prFactory.create_person("Name2") << std::endl;
    std::cout << prFactory.create_person("Name3") << std::endl;
    return 0;
}