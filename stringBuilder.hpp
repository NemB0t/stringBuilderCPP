#ifndef STRINGBUILDER_HPP
#define STRINGBUILDER_HPP

#include <string>   // for std::string
#include <cstring>  // for std::memcpy, std::strlen
#include <algorithm> // for std::max

class StringBuilder {
private:
    char* buffer;
    size_t length;
    size_t capacity;

    void grow(size_t min_capacity);

public:
    StringBuilder(size_t initial = 16);
    ~StringBuilder();

    void append(const char* s);
    void append(std::string& s);
    std::string str() const;
};

#endif // STRINGBUILDER_HPP
