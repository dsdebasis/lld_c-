#include <iostream>
using namespace std;
class TwoDShape
{
public:
    virtual double area() = 0;
};

class ThreeDShape
{
public:
    virtual double area() = 0;
    virtual double volume() = 0;
};

class Square : public TwoDShape
{
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() override
    {
        return side * side;
    }
};

class Rectangle : public TwoDShape
{
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() override
    {
        return length * width;
    }
};

class Cube : public ThreeDShape
{
private:
    double side;

public:
    Cube(double s) : side(s) {}

    double area() override
    {
        return 6 * side * side;
    }
    double volume() override
    {
        return side * side * side;
    }
};

int main()
{
    TwoDShape *square = new Square(5);
    TwoDShape *rectangle = new Rectangle(4, 6);

    ThreeDShape *cube = new Cube(4);
    cout << "Square Area: " << square->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;
}
