// clang-format off
#include "nanogui/vector.h"
#include <iostream>
#include <nanogui/nanogui.h>
// clang-format on

using namespace nanogui;

int main() {
  std::cout << "hello world" << std::endl;

  // Initialize NanoGUI
  nanogui::init();

  // Create a NanoGUI screen
  Screen screen(Vector2i(300, 200), "NanoGUI Example");

  // Create a window
  Window *window = new Window(&screen, "Button Demo");

  window->set_position(Vector2i(15, 15));
  window->set_layout(new GroupLayout());

  // Create a button
  Button *button = new Button(window, "Click me!");
  button->set_callback([]() { std::cout << "Button clicked!" << std::endl; });

  // Add the button to the window
  window->set_layout(new GroupLayout());
  screen.add_child(window);

  screen.perform_layout();

  // Main NanoGUI loop
  screen.set_visible(true);
  nanogui::mainloop();

  // Shutdown NanoGUI
  // nanogui::shutdown();

  return 0;
}
