#include "MultipleImagePrinter.hpp"

const MultipleImagePrinter &MultipleImagePrinter::operator()(const Image *const *arr, size_t count, unsigned space) const
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
                    getOutputStream() << ' ';
            inputs[i]->get(c);
            while (c != '\n')
            {
                getOutputStream() << c;
                inputs[i]->get(c);
            }
        }
        getOutputStream() << '\n';
    }
    for (unsigned i = 0; i < count; ++i)
    {
        inputs[i]->close();
        delete inputs[i];
    }
    delete[] inputs;

    return *this;
}