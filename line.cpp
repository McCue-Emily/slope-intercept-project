// file:  paddle.cpp
// lab: Slope Intercept Final
// by: Emily McCue
// org: COP 2001, 202101, 10410
// desc: implementation of a point class object
// --------------------------------------------------------
#include <iostream>
#include "point.h"
#include "line.h"
#include "slope_intercept.h"
#include <cmath>

// constructors
// --------------------------------------------------------
/**
 Default constructor - initialise empty point parameters
 */
Line::Line() {
    point_one = Point(0.0, 0.0);
    point_two = Point(0.0, 0.0);
    slope = 0.0;
    y_int = 0.0;
    length = 0.0;
    angle = 0.0;
}

/**
 Properties constructor - initialise 2-point properties to parameter values
 */
Line::Line(Point point_one, Point point_two, float slope, float y_int, float length, float angle) {
    this->point_one = point_one;
    this->point_two = point_two;
    this->slope = slope;
    this->y_int = y_int;
    this->length = length;
    this->angle = angle;

}

/**
 Properties constructor - initialise point-slope properties and to parameter values
 */
Line::Line(Point point_one, float slope, float y_int, float length, float angle) {
    this->point_one = point_one;
    this->slope = slope;
    this->y_int = y_int;
    this->point_two = Point(0.0, y_int);
    this->length = length;
    this->angle = angle;

}

// accessors
// ----------------------------------------------
// getters
Point Line::getPointOne() { return point_one; }
Point Line::getPointTwo() { return point_two; }
float Line::getSlope() { return slope; }
float Line::getYInt() { return y_int; }
float Line::getLength() { return length; }
float Line::getAngle() { return angle; }

// setters
void Line::setPointOne(Point value) { point_one = value; }
void Line::setPointTwo(Point value) { point_two = value; }
void Line::setSlope(float value) { slope = value; }
void Line::setYInt(float value) { y_int = value; }
void Line::setLength(float value) { length = value; }
void Line::setAngle(float value) { angle = value; }

// member methods
// ----------------------------------------------
/**
 Returns the difference in X between the two points
 */
float Line::differenceX(float x1, float x2) { return x2 - x1; }

/**
Returns the difference in Y between the two points
*/
float Line::differenceY(float y1, float y2) { return y2 - y1; }

/**
 Call methods to set properties of the line for method chosen by user

 Parameters:
 mode       integer values of enum Mode value
 line       line properties

 Returns:
 line       updated line properties
 */
Line Line::calcLine(int mode, Line line) {

    if (mode == TWO_POINT) {
        line.slope = slopeFrom2Point(line);
        line.y_int = slopeIntercept(line);
    } else if (mode == POINT_SLOPE) {
        line.y_int = slopeIntercept(line);
        line.point_two.setYCoordinate(line.y_int);
        line.point_two.setXCoordinate(0.0);
    }

    line.length = lineLength(line);
    line.angle = lineAngle(line);

    return line;

}

/**
 Calculates the length of the line (distance between the two points)

 Returns:
 length    length of the line as a float
 */
float Line::lineLength(Line line) {

    float diffX = differenceX(line.point_one.getXCoordinate(), line.point_two.getXCoordinate());
    float diffY = differenceY(line.point_one.getYCoordinate(), line.point_two.getYCoordinate());

    length = std::sqrt(pow(diffX, 2.0) +
                                      pow(diffY, 2.0));

    return length;

}

/**
 Calculates the angle of the line from the top of the Y-axis

 Returns:
 angle     angle of the line as a float
 */
float Line::lineAngle(Line line) {

    float diffX = differenceX(line.point_one.getXCoordinate(), line.point_two.getXCoordinate());
    float diffY = differenceY(line.point_one.getYCoordinate(), line.point_two.getYCoordinate());

    std::cout << diffX << " " << diffY << std::endl;

    int line_angle = 90 - std::atan2(diffY, diffX) * 180 / M_PI;
    angle = line_angle % 360;

    return angle;

}

/**
 Calculate the y-intercept

 Returns:
 y_int      y-intercept as float
 */
float Line::slopeIntercept(Line line) {

    y_int = (line.point_one.getYCoordinate() - (line.slope * line.point_one.getXCoordinate()));

    return y_int;

}

/**
 Calculates the slope from two points

 Returns:
 slope     slope of the line as a float
 */
float Line::slopeFrom2Point(Line line) {

    float diffX = differenceX(line.point_one.getXCoordinate(), line.point_two.getXCoordinate());
    float diffY = differenceY(line.point_one.getYCoordinate(), line.point_two.getYCoordinate());

    slope = diffY / diffX;

    return slope;

}