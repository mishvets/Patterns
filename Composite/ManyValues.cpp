#include "ManyValues.hpp"

void ManyValues::add(int val) 
{
    m_valVector.push_back(val);
}

int ManyValues::sum() const
{
    int result{0};
    for (const int val : m_valVector) {
        result += val;
    }
    return result;
}