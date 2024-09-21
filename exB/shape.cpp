#include <iostream>
# include <stdio.h>
# include <math.h>
using namespace std;

Shape::Shape(const double x, const double y, const char* shapeName){
    this->origin = Point(x,y);
    this->shapeName = new char[strlen(shapeName)+1]
    strcpy(this->shapeName, shapeName);
}

Shape::~Shape(){
    delete this->shapeName; //check first 
}

const Point& Shape::getOrigin() const {
    return origin;
}

char* Shape::getName() const {
    return shapeName;
}

void Shape::display() {
    cout << "Shape Name: " << getName() << endl
    << "X-coordinate: " << origin.getx() << endl
    << "Y-coordinate: " << origin.gety() << endl;
}

double Shape::distance(){
    
}