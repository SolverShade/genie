#include "test/t.h"
#include <GLFW/glfw3.h>
#include <genie/GenieView.hpp>
#include <iostream>

int main() {
  std::cout << "Hello, Uncle Leo!" << std::endl;

  // GenieView genieView = GenieView(640, 480, "my_window");
  T t = T();
  t.sayHello();

  return 0;
}
