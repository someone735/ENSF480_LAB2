#include <iostream>
# include <stdio.h>
# include <math.h>
#include <string.h>
#include "shape.h"
#include "point.h"
using namespace std;

Shape::Shape(const double x, const double y, const char* shapeName) : origin(x,y)
{
    this->shapeName = new char[strlen(shapeName)+1];
    strcpy(this->shapeName, shapeName);
}

Shape::~Shape(){
    delete this->shapeName; 
}

Shape& Shape::operator=(const Shape& temp){
    this->origin.setx(temp.getOrigin().getx());
    this->origin.sety(temp.getOrigin().gety());
    this-> setName(temp.getName());
    return *this;
}

const Point& Shape::getOrigin() const {
    return origin;
}

char* Shape::getName() const {
    return shapeName;
}

void Shape::setName(const char* name){
    delete this -> shapeName;
    this->shapeName = new char[strlen(name)+1];
    strcpy(this->shapeName, name);
}

void Shape::setx(const double a){
    this->origin.setx(a);
}

void Shape::sety(const double b){
    this->origin.sety(b);
}

void Shape::display() {
    cout << "Shape Name: " << getName() << endl
    << "X-coordinate: " << this->origin.getx() << endl
    << "Y-coordinate: " << this->origin.gety() << endl;
}

double Shape::distance(Shape& other){
    float x1 = pow(this->origin.getx() - other.origin.getx(), 2);
    float y2 = pow(this->origin.gety() - other.origin.gety(), 2);
    double res = sqrt(x1 + y2);
    return res;
}
double Shape::distance(Shape& the_shape, Shape& other){
    float x1 = pow(the_shape.getOrigin().getx() - other.getOrigin().getx(), 2);
    float y2 = pow(the_shape.getOrigin().getx() - other.getOrigin().gety(), 2);
    double res = sqrt(x1 + y2);
    return res;
}

void Shape::move(double dx, double dy){
    int currentx = this -> origin.getx();
    int currenty = this -> origin.gety();
    this -> origin.setx(currentx + dx);
    this -> origin.sety(currenty + dy);
}

