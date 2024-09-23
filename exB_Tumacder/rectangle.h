/*
File name: rectangle.h
Assignment: Lab 2 Excerise B
Completed by: John Tumacder 
Submission date: Sept 23, 2024
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "square.h"
class Rectangle: public Square
{
private:
    double side_b;

public:
    Rectangle(const double x, const double y, const double side_a, const double side_b, const char* shapeName);
    Rectangle(const Rectangle& temp);
    Rectangle& operator= (const Rectangle& temp);
    ~Rectangle(); //remember to program deallocate shape name
   double area() const;
   double perimeter() const;
//    Point getOrigin() const;
//    char* getName() const;
   double getSideB() const;

   
//    void setOrigin(const double x, const double y );
//    void setName(const char* name); 
    void set_side_a(const double side);
    void set_side_b(const double side);

    void display();

};
#endif