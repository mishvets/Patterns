// Expected output:
// class Person
// {
//     string name;
//     int age;
// };

#include "CodeBuilder.hpp"
#include <iostream>

int main()
{
    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
    std::cout << cb;

    return 0;
}