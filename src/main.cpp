#include <GLFW/glfw3.h>
#include <genie/GenieView.hpp>
#include <iostream>

void initWindow() {
  std::cout << "bam" << std::endl;

  if (!glfwInit()) {
    std::cout << "Failed to initialize GLFW" << std::endl;
  }

  GenieView genieView = GenieView(640, 480, "myWindow");
  GLFWwindow *window = genieView.Window;

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    // Clear the screen
    // glClear(GL_COLOR_BUFFER_BIT);

    // Swap front and back buffers
    glfwSwapBuffers(window);

    // Poll for and process events
    glfwPollEvents();
  }
}

int main() {
  std::cout << "Hello, Uncle Leo!" << std::endl;

  initWindow();

  return 0;
}
