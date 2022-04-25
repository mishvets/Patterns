#include <iostream>
#include <string>

using namespace std;

constexpr auto describeStr = " that is ";
constexpr auto connectorStr = " and ";

struct Flower
{
    virtual string str() const = 0;
};

struct Rose : Flower
{
    string introduse{"A rose"};
    string str() const override
    {
        return introduse;
    }
};

struct RedFlower : Flower
{
    const string color{"red"};
    string introduse;

    RedFlower(const Flower &flower) : introduse(flower.str())
    {
        if (introduse.find(color) != std::string::npos)
        {
            return;
        }
        if (introduse.find(describeStr) == std::string::npos)
        {
            introduse += describeStr + color;
        }
        else
        {
            introduse += connectorStr + color;
        }
    }
    string str() const override
    {
        return introduse;
    }
};

struct BlueFlower : Flower
{
    const string color{"blue"};
    string introduse;

    BlueFlower(const Flower &flower) : introduse(flower.str())
    {
        if (introduse.find(color) != std::string::npos)
        {
            return;
        }
        if (introduse.find(describeStr) == std::string::npos)
        {
            introduse += describeStr + color;
        }
        else
        {
            introduse += connectorStr + color;
        }
    }

    string str() const override
    {
        return introduse;
    }
};

int main()
{
    Rose rose;
    RedFlower redRose{rose};
    RedFlower redRedRose{redRose};
    BlueFlower blueRedRose{redRose};
    BlueFlower blueRedRedRose{redRedRose};
    cout << rose.str() << endl;
    cout << redRose.str() << endl;
    cout << redRedRose.str() << endl;
    cout << blueRedRose.str() << endl;
    cout << blueRedRedRose.str() << endl;
    return 0;
}