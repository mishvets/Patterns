#include <iostream>

struct Square
{
    int side{0};

    explicit Square(const int side)
        : side(side)
    {
    }
};

struct Rectangle
{
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const
    {
        return width() * height();
    }
};

struct SquareToRectangleAdapter : Rectangle
{
    SquareToRectangleAdapter(const Square &square) : m_square(square)
    {
    }

    int width() const final
    {
        return m_square.side;
    }

    int height() const final
    {
        return m_square.side;
    }

private:
    const Square &m_square;
};

int main()
{
    Square square(5);
    SquareToRectangleAdapter adaptedRectangle(square);
    std::cout << "Area = " << adaptedRectangle.area() << ";" << std::endl;
    square.side = 10;
    std::cout << "Area = " << adaptedRectangle.area() << ";" << std::endl;

    return 0;
}