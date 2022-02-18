// file:  line.h
// lab: Slope Intercept Final
// by: Emily McCue
// org: COP 2001, 202101, 10410
// desc: declaration of a line class object
// --------------------------------------------------------
#ifndef LINE_H
#define LINE_H

#include "point.h"

class Line {

public:

    // constructors
    Line();
    Line(Point point_one, Point point_two, float slope, float y_int, float length, float angle);
    Line(Point point_one, float slope, float y_int, float length, float angle);

    // accessors
    // ----------------------------------------------
    // getters
    Point getPointOne();
    Point getPointTwo();
    float getSlope();
    float getYInt();
    float getLength();
    float getAngle();

    // setters
    void setPointOne(Point value);
    void setPointTwo(Point value);
    void setSlope(float value);
    void setYInt(float value);
    void setLength(float value);
    void setAngle(float value);

    // member methods
    // ----------------------------------------------
    float lineLength(Line line);
    float lineAngle(Line line);
    float differenceX(float x1, float x2);
    float differenceY(float y1, float y2);
    float slopeIntercept(Line line);
    float slopeFrom2Point(Line line);
    Line calcLine(int mode, Line line);

private:

    Point point_one = Point();
    Point point_two = Point();
    float slope;
    float y_int;
    float length;
    float angle;

};

#endif //LINE_H
