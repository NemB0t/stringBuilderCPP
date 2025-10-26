#include "stringBuilder.hpp"

StringBuilder::StringBuilder(size_t initial):buffer(new char[initial]),capacity(initial),length(0){}
StringBuilder::~StringBuilder()
{
    delete[] buffer;
}

void StringBuilder::grow(size_t new_capacity)
    {
        if(length + new_capacity <= capacity)
            return;
        capacity = std::max(length+new_capacity,capacity*2);
        char* new_buffer = new char[capacity];
        std::memcpy(new_buffer,buffer,length);
        delete[] buffer;
        buffer=new_buffer;
        return;
    }

void StringBuilder::append(const char* s)
{
    size_t string_length = std::strlen(s);
    if(string_length==0)
        return;
    grow(string_length);
    std::memcpy(buffer+length,s,string_length);
    length+=string_length;
}

void StringBuilder::append(std::string& s)
{
    append(s.c_str());
}


std::string StringBuilder::str() const
{
    return std::string(buffer,length);
}