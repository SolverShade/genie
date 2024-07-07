// clang-format off
#include "GLFW/glfw3.h"
#include "nanogui/vector.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <nanogui/nanogui.h>
// clang-format on

using namespace nanogui;

int main() {
  nanogui::init();

  glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

  Screen *screen =
      new Screen(Vector2i(640, 480), "NanoGUI Transparent Window", false);

  // Set the screen's background color to be transparent (RGBA)
  screen->set_background(Color(0, 0, 0, 0));

  Window *window = new Window(screen, "Button Demo");
  window->set_position(Vector2i(15, 15));
  window->set_layout(new GroupLayout());

  Button *button = new Button(window, "Click me!");
  button->set_callback([]() { std::cout << "Button clicked!" << std::endl; });

  screen->perform_layout();
  screen->set_visible(true);

  mainloop();

  return 0;
}
