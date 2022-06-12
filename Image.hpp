#ifndef __IMAGE_HPP
#define __IMAGE_HPP
#include <iostream>
#include "String.hpp"
#include <fstream>

/// class representing image (ascii art)
class Image
{
    String path;

public:
    /// create image by showing its path
    Image(const String &p) : path(p) {}
    /// print the image to output stream
    void print(std::ostream &os = std::cout) const;
    friend class MultipleImagePrinter;
};

std::ostream &operator<<(std::ostream &os, const Image &I);

#endif