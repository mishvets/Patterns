#include <iostream>
#include <string>
using namespace std;

class IRenderer
{
public:
    IRenderer() {};
    virtual string str(const string &) const = 0;
};

class RasterRenderer : public IRenderer
{
public:
    RasterRenderer() : IRenderer(){};
    string str(const string &name) const final
    {
        return "Drawing " + name + " as pixels";
    }
};

class VectorRenderer : public IRenderer
{
public:
    VectorRenderer() : IRenderer(){};
    string str(const string &name) const final
    {
        return "Drawing " + name + " as lines";
    }
};

struct Shape
{
    string name;
    const IRenderer &renderer;

    Shape(const IRenderer &r) : renderer(r)
    {
    }

    virtual string str() const
    {
        return renderer.str(name);
    }
};

struct Triangle : Shape
{
    Triangle(const IRenderer &r) : Shape(r)
    {
        name = "Circle";
    }
};

struct Square : Shape
{
    Square(const IRenderer &r) : Shape(r)
    {
        name = "Square";
    }
};

int main()
{
    cout << Triangle(RasterRenderer()).str() << endl;
    cout << Square(VectorRenderer()).str() << endl;
    return 0;
}