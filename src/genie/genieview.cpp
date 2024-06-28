#include "GenieView.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

void onMouseClick(GLFWwindow *window, int button, int actions, int mods) {
  if (actions == 0) {
    std::cout << "mouse pressed" << std::endl;
  } else {
    std::cout << "mouse released" << std::endl;
  }
}

void onWindowFocus(GLFWwindow *window, int focused) {
  if (focused == 1) {
    std::cout << "window focused" << std::endl;
  } else {
    std::cout << "window un-focused" << std::endl;
  }
}

void GenieView::setViewInputEvents() {
  glfwSetMouseButtonCallback(Window, onMouseClick);
  glfwSetWindowFocusCallback(Window, onWindowFocus);
}

// void GenieView::setWindowAppearance() {
//  glfwMakeContextCurrent(Window);

// glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
// glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

// Enable alpha blending
// glEnable(GL_BLEND);
// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

// Clear the screen with transparent background
// glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Clear with transparent color
// glClear(GL_COLOR_BUFFER_BIT);
//}

GenieView::GenieView(GLFWwindow *window) {
  Window = window;

  // setWindowAppearance();
  setViewInputEvents();

  std::cout << "genie constructed" << std::endl;
}
