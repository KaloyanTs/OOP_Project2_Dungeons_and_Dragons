#ifndef __MY_EXCEPTION_HPP
#define __MY_EXCEPTION_HPP
#include <exception>
#include "String.hpp"

/// class inheriting std::exception knowing what is the error and where it happened
class MyException : public std::exception
{
    String errorMsg;
    String foundIn;

public:
    MyException(const String &err, const String &in = "") : errorMsg(err), foundIn(in) {}
    const char *what() const noexcept override { return errorMsg.c_str(); }
    const char *where() const { return foundIn.c_str(); }
};

#endif