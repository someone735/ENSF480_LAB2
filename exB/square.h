/*
File name: square.h
Assignment: Lab 2 Excerise B
Completed by: John Tumacder 
Submission date: Sept 23, 2024
*/

#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"
class Square: public Shape
{
private:
    double side_a;

public:
    Square(const double x, const double y, const double side_a, const char* shapeName);
    ~Square(); //remember to program deallocate shape name
   Square& operator=(const Square& temp);
   
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