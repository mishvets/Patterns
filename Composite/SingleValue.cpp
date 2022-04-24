#include "SingleValue.hpp"

SingleValue::SingleValue(const int val) : m_val(val)
{
}

int SingleValue::sum() const
{
    return m_val;
}
