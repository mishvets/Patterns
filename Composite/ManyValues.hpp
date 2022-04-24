#ifndef MANY_VALUES_HPP
#define MANY_VALUES_HPP
#include "ContainsIntegers.hpp"
#include "vector"

class ManyValues : public ContainsIntegers
{
private:
    std::vector<int> m_valVector;

public:
    void add(int val);
    int sum() const final;

};
#endif