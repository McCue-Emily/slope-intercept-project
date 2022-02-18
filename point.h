// file:  point.cpp
// lab: Slope Intercept Final
// by: Emily McCue
// org: COP 2001, 202101, 10410
// desc: declaration of a point class object
// --------------------------------------------------------
#ifndef POINT_H
#define POINT_H

class Point{

public:

    // constructors
    // ----------------------------------------------
    Point();
    Point(float x, float y);

    // accessors
    // ----------------------------------------------
    // getters
    float getXCoordinate();
    float getYCoordinate();

    // setters
    void setXCoordinate(float value);
    void setYCoordinate(float value);

private:

    float x_coordinate;
    float y_coordinate;

};

#endif //POINT_H
