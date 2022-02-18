// file:  breakout.cpp
// lab: Slope Intercept Final
// by: Emily McCue
// org: COP 2001, 202101, 10410
// desc: main configuration header file for a slope intercept graph
// --------------------------------------------------------
#ifndef SLOPE_INTERCEPT_H
#define SLOPE_INTERCEPT_H

#include <string>
#include "point.h"
#include "line.h"

// Global constants
// ----------------------------------------------
const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE= "Linear Graph";

// enums
// ----------------------------------------------
enum Mode {
    TWO_POINT = 1,
    POINT_SLOPE = 2,
    EXIT = 3
};

#endif
