// file:    slope_intercept.cpp
// lab:     Slope Intercept Final
// by:      Emily McCue
// org:     COP 2001, 202101, 10410
// desc:    main application file for a slope intercept graph
// --------------------------------------------------------
#include <iostream>
#include <iomanip>

#include "fgcugl.h"
#include "slope_intercept.h"
#include "point.h"
#include "line.h"

// Function prototypes
Mode getProblem();
Point getPoint();
Line get2Point(Line line);
Line getPointSlope(Line line);
void displayLine(Line line);
void display2Pt(Line line);
void displayPointSlope(Line line);
void displaySlopeIntercept(Line line);
void drawLine(Line line);

int main() {

    Line line;
    Mode mode = getProblem();

    while (mode != EXIT) {

        if (mode == TWO_POINT) {

            line = get2Point(line);

            line = line.calcLine(mode, line);

            displayLine(line);

            display2Pt(line);

        } else if (mode == POINT_SLOPE) {

            line = getPointSlope(line);

            line = line.calcLine(mode, line);

            displayLine(line);

            displayPointSlope(line);

        }

        displaySlopeIntercept(line);

        drawLine(line);

        mode = getProblem();

    }

    return 0;

}

/**
 Displays the user menu, prompt for menu choice, and get user input

 Parameters:

 Returns:
 mode      the mode selected (default EXIT)
 */
Mode getProblem() {

    std::cout << "Select the form that you would like to convert to slope-intercept form: " <<std::endl <<
              "\t\t1) Two-point form (you know the two points of the line)" << std::endl <<
              "\t\t2) Point-slope form (you know the line's slope and one point)" << std::endl <<
              "\t\t3) Exit" << std:: endl;
    int mode_selection;
    std::cin >> mode_selection;

    Mode mode;

    if (mode_selection == 1) {
        mode = TWO_POINT;
    } else if (mode_selection == 2){
        mode = POINT_SLOPE;
    } else {
        mode = EXIT;
    }

    return mode;

}

/**
 Prompt user for an X and Y coordinate

 Parameters:

 Returns:
 Point(x, y)      the X and Y coordinates of the point
 */
Point getPoint() {

    float x;
    float y;

    std::cout << "Enter X and Y coordinates separated by spaces: ";
    std::cin >> x >> y;

    Point(x, y);

    return Point(x, y);

}

/**
 Populate the two point properties of the line

 Parameters:
 line       line properties

 Returns:
 line       updated line properties
 */
Line get2Point(Line line) {

    std::cout << "Enter the First point:" << std::endl;
    std::cin.ignore();
    line.setPointOne(getPoint());

    std::cout << "Enter the second point:" << std::endl;
    std::cin.ignore();
    line.setPointTwo(getPoint());

    return line;

}

/**
 Populate one of the point properties and prompt the user for a slope value

 Parameters:
 line      line properties

 Returns:
 line      updated line properties
 */
Line getPointSlope(Line line) {

    std::cout << "Enter a point for the line: " << std::endl;
    std::cin.ignore();
    line.setPointOne(getPoint());

    std::cout << "Enter the slope of the line: ";
    float slope_point;
    std::cin >> slope_point;
    line.setSlope(slope_point);

    return line;

}

/**
 Displays the Line property values on the console

 Parameters:
 line           line properties

 Returns:
 void
 */
void displayLine(Line line) {

    std::cout << "Line:" << std::endl <<
              "\tPoint-1       (" << line.getPointOne().getXCoordinate() << ", " <<
              line.getPointOne().getYCoordinate() << ")" << std::endl <<
              "\tPoint-2       (" << line.getPointTwo().getXCoordinate() << ", " <<
              line.getPointTwo().getYCoordinate() << ")" << std::endl << std::setprecision(2) << std::fixed <<
              "\tSlope        =  " << line.getSlope() << std::endl << std::setprecision(1) <<
              "\tY-Intercept  =  " << line.getYInt() << std::endl << std::setprecision(0) <<
              "\tLength       =  " << line.getLength() << std::endl <<
              "\tAngle        =  " << line.getAngle() << std::endl << std::endl;

}

/**
 Displays the two-point form of the line on the console

 Parameters:
 line           line properties

 Returns:
 void
 */
void display2Pt(Line line) {

    std::cout << "Two-point form:" << std::endl <<
              "\t\t(" << line.getPointTwo().getYCoordinate() << " - " << line.getPointOne().getYCoordinate() <<
              ")" << std::endl << "\tm = ----------------" << std:: endl << "\t\t(" <<
              line.getPointTwo().getXCoordinate() << " - " << line.getPointOne().getXCoordinate() << ")" <<
              std::endl << std::endl;

}

/**
 Displays the point-slope form of the line on the console

 Parameters:
 line           line properties

 Returns:
 void
 */
void displayPointSlope(Line line) {

    std::cout << "Point-slope form:" << std::endl <<
              "\t y - " << line.getPointOne().getYCoordinate() << " = " << std::setprecision(1) <<
              std::fixed << line.getSlope() << "(x - " << std::setprecision(0) <<
              line.getPointOne().getXCoordinate() << ")" << std::endl << std::endl;

}

/**
 Displays the slope-intercept form of the line on the console

 Parameters:
 line           line properties

 Returns:
 void
 */
void displaySlopeIntercept(Line line) {

    std::cout << "Slope-intercept form:" << std::endl << std::setprecision(2) << std::fixed <<
              "\ty = " << line.getSlope() << "x + " << std::setprecision(1) << line.getYInt() <<
              std::endl << std::endl;

}

/**
 Graphs the points, and the line on an OpenGL window with X and Y axis

 Parameters:
 line           line properties
 point          point properties

 Returns:
 void
 */
void drawLine(Line line) {

    fgcugl::openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, false);

    bool close_window = false;
    while (!close_window) {

        // x & y axis
        fgcugl::drawLine(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2,
                         1, fgcugl::Silver);
        fgcugl::drawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT,
                         1, fgcugl::Silver);

        // line connecting the points
        fgcugl::drawLine(line.getPointOne().getXCoordinate() + (WINDOW_WIDTH / 2),
                         line.getPointOne().getYCoordinate() + (WINDOW_HEIGHT / 2),
                         line.getPointTwo().getXCoordinate() + (WINDOW_WIDTH / 2),
                         line.getPointTwo().getYCoordinate() + (WINDOW_HEIGHT / 2), 1,
                         fgcugl::Blue);

        // point one
        fgcugl::drawCircle(line.getPointOne().getXCoordinate() + (WINDOW_WIDTH / 2),
                           line.getPointOne().getYCoordinate() + (WINDOW_HEIGHT / 2), 2,
                           fgcugl::Purple);

        // point two
        fgcugl::drawCircle(line.getPointTwo().getXCoordinate() + (WINDOW_WIDTH / 2),
                           line.getPointTwo().getYCoordinate() + (WINDOW_HEIGHT / 2), 2,
                           fgcugl::Purple);


        fgcugl::windowPaint();

        fgcugl::getEvents();

        close_window = close_window || fgcugl::windowClosing();

    }

    fgcugl::cleanup();

}