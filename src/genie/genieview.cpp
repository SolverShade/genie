#include "GenieView.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

void onMouseClick(GLFWwindow *window, int a, int b, int c) {
  std::cout << "example event call" << std::endl;
}

void onWindowFocus(GLFWwindow *window, int focused) {
  if (focused == 1) {
    std::cout << "window focused" << std::endl;
  }
}

void GenieView::setViewInputEvents() {
  // glfwSetMouseButtonCallback(Window, onMouseClick);
  glfwSetWindowFocusCallback(Window, onWindowFocus);
}

GenieView::GenieView(GLFWwindow *window) {
  Window = window;

  setViewInputEvents();

  std::cout << "genie constructed" << std::endl;
}
