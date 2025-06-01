//isp breaked
#include<iostream>
using namespace std;

//single interface for all the shaped (Vioaltes ISP)
//never force the child class to implement the methods that it does not need
//it is better to define a common interface than evey class havas its own method

class Shape{
   public:
   virtual double area()=0;
   virtual double volume()=0; //nto every shape has volume

};

class Square:public Shape{
    private: 
    double side;

    public:
     Square(double s):side(s){}

    double area() override{
        return side* side;
    }

    double volume() override{
        throw logic_error("Square has no volume");
        //unnecessary error handling
    }
};

class Rectangle:public Shape{
    private: 
    double length,width;
    public:
    Rectangle(double l, double w):length(l),width(w){}
    
    double area() override{
        return length*width;
    }

    double volume() override{
        throw logic_error("Rectangle has no volume");
        //unnecessary error handling
    }
};


class Cube :public Shape{
    private:
    double side;

    public:
    Cube(double s):side(s){}

    double area() override{
        return 6*side*side;
    }
    double volume() override{
        return side*side*side;
    }
};
int main (){

    Shape* square = new Square(4);
    Shape* rectangle = new Rectangle(4,6);
    Shape* cube = new Cube(4);

    cout << "Square Area: " << square->area() << endl;
    cout << "Rectangle Area: " << rectangle->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;

    try {
        cout << "Square Volume: " << square->volume() << endl; // Will throw an exception
    } catch (logic_error& e) {
        cout << "Exception: " << e.what() << endl;
    }
    
    return 0;
}