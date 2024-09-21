#include "point.h"
#include <iostream>
# include <stdio.h>
# include <math.h>
using namespace std;

int Point::id = 1000;

Point::Point(const double x, const double y)
{
    this->x = x;
    this->y = y;
    this->id = ++id;
    // cout << this-> id << endl;
}

Point::~Point()
{
}

int Point::getx()const{
    return x;
};
int Point::gety()const{
    return y;
};
void Point::setx(const double a){
    this->x = a;
};
void Point::sety(const double b){
    this->x = b;
};
int Point::getid() const{ // **needs fix**
    return this->id;
};

void Point::display(){
    cout << "X-coordinate: " << x << endl << "Y-coordinate: " << endl;
};

double Point::distance(const Point& a){
    float x1 = pow(this-> getx() - a.getx(), 2);
    float y2 = pow(this-> gety() - a.gety(), 2);
    double res = sqrt(x1 + y2);
    return res;
}
double Point::distance(const Point& a, const Point& b){
    float x1 = pow(b.getx() - a.getx(), 2);
    float y2 = pow(b.gety() - a.gety(), 2);
    double res = sqrt(x1 + y2);
    return res;
};

int Point::counter() const{
    return id - 1000;
}

