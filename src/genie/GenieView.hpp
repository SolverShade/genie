#ifndef GENIEVIEW_HPP
#define GENIEVIEW_HPP

#include <GLFW/glfw3.h>
#include <string>

class GenieView {
public:
  GenieView(int width, int height, std::string title);

  GLFWwindow *Window = glfwCreateWindow(640, 480, "myTitle", NULL, NULL);

private:
  int width;
  int height;
  std::string title;
};

#endif
