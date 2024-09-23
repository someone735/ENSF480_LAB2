#ifndef POINT_H
#define POINT_H

class Point
{
private:
    double x;
    double y;
    int id;
    static int globalID;
public:
    Point(const double x, const double y);
    ~Point();
    int getx()const;
    int gety()const;
    void setx(const double a);
    void sety(const double b);
    int getid()const;

    void display();
    
    double distance(const Point& a);
    static double distance(const Point& a, const Point& b);

    int counter()const;

    
};
#endif
