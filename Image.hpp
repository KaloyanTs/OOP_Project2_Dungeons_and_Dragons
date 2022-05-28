#ifndef __IMAGE_HPP
#define __IMAGE_HPP
#include <iostream>
#include "String.hpp"
#include <fstream>

class Image
{
    String path;

public:
    Image(const String &p) : path(p) {}
    void print(std::ostream &os = std::cout) const;
    friend class MultipleImagePrinter;
};

std::ostream &operator<<(std::ostream &os, const Image &I);

#endif