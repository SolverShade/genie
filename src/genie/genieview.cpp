#include "GenieView.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

GenieView::GenieView(int width, int height, std::string title) {
  GenieView::width = width;
  GenieView::height = height;
  GenieView::title = title;

  std::cout << "genie constructed" << std::endl;
}
