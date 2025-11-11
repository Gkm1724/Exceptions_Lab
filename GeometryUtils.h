//
// Created by Christopher Vaughn on 10/29/25.
//
/**
 * @file GeometryUtils.h
 * @brief Declares a library of utility functions for calculating shape areas.
 *
 * This file contains the function declarations (prototypes) for an
 * overloaded 'calculateArea' function and a 'calculateCircleArea' function.
 *
 * @author [Gabriel Martinez]
 * @date [11/10/2025]
 * @version 1.0
 */

#pragma once
#include <stdexcept>

double calculateArea(double side);                   // Square
double calculateArea(double length, double width);   // Rectangle
double calculateCircleArea(double radius);           // Circle

double calculatePerimeter(double side);              // Square
double calculatePerimeter(double length, double width); // Rectangle
double calculateCirclePerimeter(double radius);      // Circle
