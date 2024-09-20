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
};
#endif
