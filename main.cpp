#include <iostream>
#include "stringBuilder.hpp"

int main() {
    StringBuilder sb;
    sb.append("Hello, ");
    sb.append("World!");
    std::cout << sb.str() << std::endl;

    sb.append(" Let's build more text.");
    std::cout << sb.str() << std::endl;

    return 0;
}