#include <iostream> 
#include <GLFW/glfw3.h>
#include "example.cpp"

int main() {
    std::cout << "Hello, Uncle Leo!" << std::endl;

    Example a; 
    a.create_window();

    return 0; 
}

