//
// Created by Christopher Vaughn on 10/29/25.
//
/**
 * @file GeometryUtils.cpp
 * @brief Implements the geometry utility functions.
 *
 * This file contains the function definitions for calculating the areas
 * of squares, rectangles, and circles. It is responsible for
 * validating input and throwing exceptions on invalid data.
 *
 * @author [Your Name Here]
 * @date [Current Date]
 * @version 1.0
 */

#include "GeometryUtils.h"
#include <cmath>
#include <stdexcept>
#include <string>

using namespace std;

double calculateArea(double side) {
    if (side <= 0)
        throw invalid_argument("Square side must be positive: " + to_string(side));
    return side * side;
}

double calculateArea(double length, double width) {
    if (length <= 0 || width <= 0)
        throw invalid_argument("Rectangle dimensions must be positive: " + to_string(length) + ", " + to_string(width));
    return length * width;
}

double calculateCircleArea(double radius) {
    if (radius <= 0)
        throw invalid_argument("Circle radius must be positive: " + to_string(radius));
    const double PI = 3.141592653589793;
    return PI * radius * radius;
}

double calculatePerimeter(double side) {
    if (side <= 0)
        throw invalid_argument("Square side must be positive: " + to_string(side));
    return 4 * side;
}

double calculatePerimeter(double length, double width) {
    if (length <= 0 || width <= 0)
        throw invalid_argument("Rectangle dimensions must be positive: " + to_string(length) + ", " + to_string(width));
    return 2 * (length + width);
}

double calculateCirclePerimeter(double radius) {
    if (radius <= 0)
        throw invalid_argument("Circle radius must be positive: " + to_string(radius));
    const double PI = 3.141592653589793;
    return 2 * PI * radius;
}
