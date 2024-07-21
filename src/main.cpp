// clang-format off
#include "genie/GenieView.hpp"
#include "nanogui/common.h"
#include "nanogui/vector.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <filesystem>
#include <iostream>
#include <map>
#include <nanogui/nanogui.h>
#include <graphics/ContentLoader.hpp>
// clang-format on

using namespace nanogui;

std::string p_path = std::filesystem::current_path().parent_path().string();

int main() {
  nanogui::init();

  glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

  Screen *screen =
      new Screen(Vector2i(640, 480), "NanoGUI Transparent Window", false);

  ContentLoader contentLoader = ContentLoader();

  NVGcontext *ctx = screen->nvg_context();

  std::cout << p_path + "/content" << std::endl;

  std::map<std::string, shared_ptr<Texture>> images =
      contentLoader.LoadTextures(ctx, p_path + "/content");

  GenieView genieView = GenieView(screen);
  screen->draw_all();
  screen->set_visible(true);

  mainloop();

  nanogui::shutdown();

  return 0;
}
