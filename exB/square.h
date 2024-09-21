#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
class Square: public Shape
{
private:
    double side_a;

public:
    Square(const double x, const double y, const char* shapeName, const double side_a);
    ~Square(); //remember to program deallocate shape name
   double area() const;
   double perimeter() const;
   Point getOrigin() const;
   char* getName() const;
   double getSideA() const;

//    void setOrigin(const double x, const double y );
//    void setName(const char* name); 
    void setSideA(const double side);

    void display();

};
#endif