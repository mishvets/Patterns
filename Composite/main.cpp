#include <iostream>
#include "SingleValue.hpp"
#include "ManyValues.hpp"

using namespace std;

int sum(const vector<ContainsIntegers*> items)
{
    int result{0};
    for (const ContainsIntegers* item : items) {
        result += item->sum();
    }
    return result;
}

int main()
{
    SingleValue singleValue{1};
    ManyValues otherValues;
    otherValues.add(2);
    otherValues.add(3);
    cout << sum({&singleValue, &otherValues}) << endl;
    return 0;
}