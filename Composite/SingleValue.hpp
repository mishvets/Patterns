#ifndef SINGLE_VALUE_HPP
#define SINGLE_VALUE_HPP
#include "ContainsIntegers.hpp"

class SingleValue : public ContainsIntegers
{
private:
    int m_val;
public:
    explicit SingleValue(const int val);

    int sum() const final;
};
#endif
