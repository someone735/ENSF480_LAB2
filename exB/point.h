#ifndef POINT_H
#define POINT_H

class Point
{
private:
    float x;
    float y;
    int id;
public:
    Point(const int x, const int y);
    ~Point();
    void get_x()const;
    void get_y()const;
    int set_x(const int a);
    int set_y(const int b);

    
};
#endif
