#ifndef __IMAGE_HPP
#define __IMAGE_HPP
#include <iostream>
#include <string>
#include <fstream>

class Image
{
    std::string path;

public:
    Image(const std::string &p) : path(p) {}
    void print(std::ostream &os = std::cout) const;
};

std::ostream &operator<<(std::ostream &os,const Image &I);

#endif