// clang-format off
#include "genie/GenieView.hpp"
#include "nanogui/vector.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <nanogui/nanogui.h>
#include <nanogui/opengl.h>
// clang-format on

using namespace nanogui;

int main() {
  nanogui::init();

  glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);

  Screen *screen =
      new Screen(Vector2i(640, 480), "NanoGUI Transparent Window", false);

  GenieView genieView = GenieView(screen);
  screen->draw_all();
  screen->set_visible(true);

  mainloop();

  nanogui::shutdown();

  return 0;
}
