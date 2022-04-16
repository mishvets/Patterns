#include <iostream>
using namespace std;

struct Point
{
    int x{0}, y{0};

    Point() {}

    Point(const int x, const int y) : x{x}, y{y} {}

    ~Point()
    {
        cout << "Destructor Point: " << *(this) << endl;
    }

    friend ostream &operator<<(ostream &os, const Point &obj)
    {
        os << "x = " << obj.x << ", y = " << obj.y;
        return os;
    }
};

struct Line
{
    Point *start, *end;

    Line(Point *const start, Point *const end)
        : start(start), end(end)
    {
        std::cout << "Line Constructor " << std::endl;
    }

    ~Line()
    {
        cout << "Destructor Line: " << *this << endl;
        delete start;
        delete end;
    }

    Line deep_copy() const
    {
        if (start && end)
        {
            Point *startCopy = new Point(this->start->x, this->start->y);
            Point *endCopy = new Point(this->end->x, this->end->y);
            return {startCopy, endCopy};
        }
        return {nullptr, nullptr};
    }

    friend ostream &operator<<(ostream &os, const Line &obj)
    {
        os << "start - " << *(obj.start) << ", end - " << *(obj.end) << ";";
        return os;
    }
};

int main()
{
    Point *p1 = new Point{0, 1};
    Point *p2 = new Point{1, 2};
    Line line1{p1, p2};
    auto line2 = line1.deep_copy();
    line2.start->x = 10;
    line2.end->y = 10;
    std::cout << "Orig: " << line1 << std::endl;
    std::cout << "Copy: " << line2 << std::endl;

    return 0;
}