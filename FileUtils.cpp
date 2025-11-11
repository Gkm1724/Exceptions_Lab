//
// Created by Christopher Vaughn on 10/29/25.
//
/**
 * @file FileUtils.cpp
 * @brief Implements utility functions for handling file operations.
 *
 * @author [Your Name Here]
 * @date [Current Date]
 * @version 1.0
 */

#include "FileUtils.h"
#include "Exceptions.h"
#include <iostream>

using namespace std;

void openFileForReading(std::ifstream& file, const std::string& filename) {
    file.open(filename);
    if (!file.is_open()) {
        throw FileOpenException("Error: Could not open file: " + filename);
    }
}
