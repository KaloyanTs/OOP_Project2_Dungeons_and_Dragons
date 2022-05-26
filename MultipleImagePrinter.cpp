#include "MultipleImagePrinter.hpp"

MultipleImagePrinter &MultipleImagePrinter::operator()(const Image *const *arr, size_t count, unsigned space)
{
    std::ifstream **inputs = new std::ifstream *[count];
    char c;
    for (size_t i = 0; i < count; ++i)
        inputs[i] = new std::ifstream(arr[i]->path);
    while (!inputs[count - 1]->eof())
    {
        for (unsigned i = 0; i < count; ++i)
        {
            if (i)
                for (unsigned i = 0; i < space; ++i)
                    std::cout << ' ';
            inputs[i]->get(c);
            while (c != '\n')
            {
                getOutputStream() << c;
                inputs[i]->get(c);
            }
        }
        std::cout << '\n';
    }
    for (unsigned i = 0; i < count; ++i)
    {
        inputs[i]->close();
        delete inputs[i];
    }
    delete[] inputs;

    return *this;
}