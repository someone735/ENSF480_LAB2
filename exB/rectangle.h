#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "square.h"
class Rectangle: public Square
{
private:
    double side_b;

public:
    Rectangle(const double x, const double y, const double side_a, const double side_b, const char* shapeName);
    ~Rectangle(); //remember to program deallocate shape name
   double area() const;
   double perimeter() const;
//    Point getOrigin() const;
//    char* getName() const;
   double getSideB() const;

   
//    void setOrigin(const double x, const double y );
//    void setName(const char* name); 
    void setSideB(const double side);

    void display();

};
#endif