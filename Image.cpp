#include "Image.hpp"

void Image::print(std::ostream &os) const
{
    std::ifstream ifs(path.c_str(), std::ios::in);
    if (!ifs)
        throw 1;
    char c;
    while (!ifs.eof())
    {
        ifs.get(c);
        os << c;
    }
    ifs.close();
}

std::ostream &operator<<(std::ostream &os, const Image &I)
{
    I.print(os);
    return os;
}
