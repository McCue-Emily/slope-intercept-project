// file:  paddle.cpp
// lab: Slope Intercept Final
// by: Emily McCue
// org: COP 2001, 202101, 10410
// desc: implementation of a point class object
// --------------------------------------------------------
#include "point.h"

// constructors
// --------------------------------------------------------
/**
 Default constructor - initialise X and Y coordinates
 */
Point::Point() {
    x_coordinate = 0.0;
    y_coordinate = 0.0;
}

/**
 Properties constructor - initialise to parameter values
 */
Point::Point(float x, float y) {
    x_coordinate = x;
    y_coordinate = y;
}

// accessors
// --------------------------------------------------------
// getters
float Point::getXCoordinate() { return x_coordinate; }
float Point::getYCoordinate() { return y_coordinate; }

// setters
void Point::setXCoordinate(float value) { x_coordinate = value; }
void Point::setYCoordinate(float value) { y_coordinate = value; }
