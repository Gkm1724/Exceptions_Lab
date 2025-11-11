//
// Created by Christopher Vaughn on 10/29/25.
//

/**
 * @file FileUtils.h
 * @brief Declares utility functions for handling file operations.
 *
 * @author [Your Name Here]
 * @date [Current Date]
 * @version 1.0
 */

#pragma once

#include <fstream>
#include <string>

/**
 * @brief Attempts to open a file for reading.
 * @throws FileOpenException if the file cannot be opened.
 */
void openFileForReading(std::ifstream& file, const std::string& filename);
