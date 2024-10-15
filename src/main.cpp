#include <iostream>
#include "hello_world.h"

int main() {
    HelloWorld hello_world;
    std::cout << hello_world.GetMessage() << std::endl;
    return 0;
}