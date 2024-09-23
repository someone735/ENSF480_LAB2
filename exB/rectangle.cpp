#include <iostream>
# include <stdio.h>
# include <math.h>
# include "rectangle.h"

using namespace std; 

Rectangle::Rectangle(const double x, const double y, const double side_a, const double side_b, const char* shapeName) : Square(x,y, side_a, shapeName) {
    this -> side_b = side_b;
}

Rectangle::Rectangle(const Rectangle& temp)
    : Square(temp.getOrigin().getx(), temp.getOrigin().gety(), temp.getSideA(), temp.getName())
{
    this -> side_b = temp.getSideB();
}

Rectangle& Rectangle::operator=(const Rectangle& temp){
    if (this != &temp){
        this -> side_b = temp.getSideB();
        Square::operator=(temp);
    }
    return *this;
}

Rectangle::~Rectangle(){}

double Rectangle::area() const{
    double res = this -> side_b * Square::getSideA();
    return res;
}

double Rectangle::perimeter() const {
    double res = this -> side_b * 2 + (Square::getSideA())*2;
    return res;
}

double Rectangle::getSideB() const {
    return this -> side_b;
}

void Rectangle::set_side_a(const double side){
    Square::setSideA(side);
}

void Rectangle::set_side_b(const double side){
    this -> side_b = side;
}

void Rectangle::display(){
    Shape::display();
    cout << "Side a: " << Square::getSideA() << endl
    << "Side b: " << getSideB() << endl 
    << "Area: " << area() << endl
    << "Perimeter: " << perimeter() << endl;
}