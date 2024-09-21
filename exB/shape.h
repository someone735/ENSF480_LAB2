#ifndef SHAPE_H
#define SHAPE_H
#include "point.h"
class Shape
{
private:
    Point origin;
    char* shapeName;

public:
    Shape(const Point& origin, const char* shapeName);
    ~Shape(); //remember to program deallocate shape name
    Point getOrigin()const;
    char* getName()const;

    void display();
    
    double distance(Shape& other);
    static double distance(Shape& the_shape, Shape& other);

    void move(double dx, double dy); 

};
#endif