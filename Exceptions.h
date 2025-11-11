/**
* @file Exceptions.h
 * @brief Declares custom exception classes for the shape parser.
 *
 * This file defines the interfaces for custom exceptions,
 * including FileOpenException and ParseException.
 *
 * @author [Gabriel Martinez]
 * @date [11/10/2025]
 * @version 1.0
 */

#pragma once

#include <exception>
#include <string>

/**
 * @class FileOpenException
 * @brief Exception thrown when a file fails to open.
 */
class FileOpenException : public std::exception {
private:
    std::string msg;
public:
    explicit FileOpenException(const std::string& message) : msg(message) {}
    virtual const char* what() const noexcept override { return msg.c_str(); }
};

/**
 * @class ParseException
 * @brief Exception thrown when a line in the data file is malformed.
 */
class ParseException : public std::exception {
private:
    std::string msg;
public:
    explicit ParseException(const std::string& message) : msg(message) {}
    virtual const char* what() const noexcept override { return msg.c_str(); }
};
