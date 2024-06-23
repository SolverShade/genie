#ifndef GENIEVIEW_HPP
#define GENIEVIEW_HPP

#include <GLFW/glfw3.h>
#include <string>

class GenieView {
public:
  GenieView(GLFWwindow *window);
  GLFWwindow *Window;

private:
  void setViewInputEvents();

  int width;
  int height;
  std::string title;
};

#endif
