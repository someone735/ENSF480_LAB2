#include <iostream>
# include <stdio.h>
# include <math.h>
#include "square.h"
#include "shape.h"

using namespace std;

Square::Square(const double x, const double y,const double side_a, const char* shapeName): Shape(x, y, shapeName){
    this -> side_a = side_a;
}

Square::~Square(){} //shapeName is already deallocated in shape

double Square::area() const{
    return pow(side_a,2);
}

double Square::perimeter() const{
    return side_a*4;
}

Point Square::getOrigin() const {
    return Shape::getOrigin();
}

char* Square::getName() const {
    return Shape::getName();
}

double Square::getSideA() const {
    return side_a;
}

void Square::setSideA(const double side){
    this -> side_a = side;
}

void Sqaure::display(){
    cout << "0";
}