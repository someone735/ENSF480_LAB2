#ifndef SHAPE_H
#define SHAPE_H
#include "point.h"
class Shape
{
private:
    Point origin;
    char* shapeName;

public:
    Shape(const double x, const double, const char* shapeName);
    ~Shape(); //remember to program deallocate shape name
    Shape& operator = (const Shape& temp);
    
    const Point& getOrigin()const;
    char* getName()const;
    void setName(const char* name);
    void setx(const double a);
    void sety(const double b);


    void display();
    
    double distance(Shape& other);
    static double distance(Shape& the_shape, Shape& other);

    void move(double dx, double dy); 

};
#endif