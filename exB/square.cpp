/*
File name: square.cpp
Assignment: Lab 2 Excerise B
Completed by: John Tumacder 
Submission date: Sept 23, 2024
*/

#include <iostream>
# include <math.h>
# include <string.h>
#include "square.h"
// #include "shape.h"

using namespace std;

Square::Square(const double x, const double y,const double side_a, const char* shapeName): Shape(x, y, shapeName){
    this -> side_a = side_a;
}

Square::~Square(){} //shapeName is already deallocated in shape


Square& Square::operator= (const Square& temp){
    if (this != &temp){
        this -> side_a = temp.getSideA();
        Shape::operator=(temp);
    }
    return *this;
}
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

void Square::display(){
    Shape::display();
    cout << "Side a: " << getSideA() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl; 
}