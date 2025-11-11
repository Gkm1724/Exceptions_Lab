/**
 * @file main.cpp
 * @brief Main client program for the ShapeFile Parser.
 *
 * This program reads shape data from a file, validates it, and calculates
 * areas. It handles all file and data exceptions.
 *
 * @author [Gabriel Martinez]
 * @date [11/10/2025]
 * @version 1.0
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdexcept>

#include "GeometryUtils.h"
#include "Exceptions.h"
#include "FileUtils.h"

using namespace std;

int main() {
    cout << fixed << setprecision(2);
    string filename;
    ifstream file;
    int lineNumber = 0;

    cout << "Enter filename: ";
    cin >> filename;

    // --- 1. File Opening Logic ---
    try {
        openFileForReading(file, filename);
        cout << "File opened successfully: " << filename << endl;
    }
    catch (const FileOpenException& e) {
        cerr << e.what() << endl;
        cout << "Enter alternative filename: ";
        cin >> filename;
        try {
            openFileForReading(file, filename);
            cout << "File opened successfully: " << filename << endl;
        }
        catch (const FileOpenException& e2) {
            cerr << "Error: Failed to open alternative file. Exiting." << endl;
            return 1;
        }
    }

    cout << "--- Processing Shapes ---" << endl;
    string shapeType;

    // --- 2. File Parsing Logic ---
    while (file >> shapeType) {
        lineNumber++;

        try {
            if (shapeType == "square") {
                double side;
                file >> side;
                double area = calculateArea(side);
                double perimeter = calculatePerimeter(side);
                cout << "Line " << lineNumber << ": Square | Area = " << area << " | Perimeter = " << perimeter << endl;
            }
            else if (shapeType == "rectangle") {
                double length, width;
                file >> length >> width;
                double area = calculateArea(length, width);
                double perimeter = calculatePerimeter(length, width);
                cout << "Line " << lineNumber << ": Rectangle | Area = " << area << " | Perimeter = " << perimeter << endl;
            }
            else if (shapeType == "circle") {
                double radius;
                file >> radius;
                double area = calculateCircleArea(radius);
                double perimeter = calculateCirclePerimeter(radius);
                cout << "Line " << lineNumber << ": Circle | Area = " << area << " | Perimeter = " << perimeter << endl;
            }
            else {
                // Throw exception for unknown shape
                throw ParseException("Line " + to_string(lineNumber) + ": Unknown shape type '" + shapeType + "'");
            }
        }
        catch (const ParseException& e) {
            cerr << e.what() << endl;
        }
        catch (const invalid_argument& e) {
            cerr << "Line " << lineNumber << ": Invalid argument - " << e.what() << endl;
        }
        catch (const exception& e) {
            cerr << "Line " << lineNumber << ": Unexpected error - " << e.what() << endl;
        }
    }

    cout << "--- Processing Complete ---" << endl;
    file.close();
    return 0;
}
