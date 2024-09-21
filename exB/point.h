#ifndef POINT_H
#define POINT_H

class Point
{
private:
    float x;
    float y;
    int id;
public:
    Point(const double x, const double y);
    ~Point();
    int get_x()const;
    int get_y()const;
    void set_x(const int a);
    void set_y(const int b);
    int get_id()const;

    void display();
    
    double distance_from(const Point& a);
    static double distance_from();

    
};
#endif
