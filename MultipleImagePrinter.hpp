#ifndef __MULTIPLE_IMAGE_PRINTER_HPP
#define __MULTIPLE_IMAGE_PRINTER_HPP
#include "Printer.hpp"
#include "Image.hpp"

class MultipleImagePrinter : public Printer
{
public:
    MultipleImagePrinter(std::ostream &os = std::cout) : Printer(os) {}
    const MultipleImagePrinter &operator()(const Image *const *arr, size_t count, unsigned space = 0) const;
};

#endif