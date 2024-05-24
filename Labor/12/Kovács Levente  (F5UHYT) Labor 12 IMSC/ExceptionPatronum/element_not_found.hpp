#pragma once

#include <exception>

template <class T>
class element_not_found : public std::logic_error
{
private:
    T element;

public:
    element_not_found(const T &element) : element(element) ~element_not_found() {}

    const T &getElement() const { return element; }

    const char *what() noexcept override { return "Element not found!"; }
};