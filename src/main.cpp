// clang-format off
#include "genie/GenieView.hpp"
#include "graphics/Content.hpp"
#include "nanogui/common.h"
#include "nanogui/vector.h"
#include <glad.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <filesystem>
#include <iostream>
#include <nanogui/nanogui.h>

// GLFW
#if defined(NANOGUI_USE_OPENGL)
#  if defined(NANOGUI_GLAD)
#    if defined(NANOGUI_SHARED) && !defined(GLAD_GLAPI_EXPORT)
#      define GLAD_GLAPI_EXPORT
#    endif
#     include <glad.h>
#  else
#    if defined(__APPLE__)
#      define GLFW_INCLUDE_GLCOREARB
#    else
#      define GL_GLEXT_PROTOTYPES
#    endif
#  endif
#elif defined(NANOGUI_USE_GLES)
#  define GLFW_INCLUDE_ES2
#endif
// clang-format on

using namespace nanogui;

std::string p_path = std::filesystem::current_path().string();

int main() {
  nanogui::init();

  if (!glfwInit()) {
    cout << "glfw init failed" << endl;
  }

  glfwSetTime(0);

  glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);

  glfwWindowHint(GLFW_SAMPLES, 0);
  glfwWindowHint(GLFW_RED_BITS, 8);
  glfwWindowHint(GLFW_GREEN_BITS, 8);
  glfwWindowHint(GLFW_BLUE_BITS, 8);
  glfwWindowHint(GLFW_ALPHA_BITS, 8);
  glfwWindowHint(GLFW_STENCIL_BITS, 8);
  glfwWindowHint(GLFW_DEPTH_BITS, 24);
  glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

  GLFWwindow *window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    printf("Failed to initialize Glad");
    return -1;
  }

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Screen *screen =
      new Screen(Vector2i(640, 480), "NanoGUI Transparent Window", false);

  NVGcontext *ctx = screen->nvg_context();

  std::cout << "contentpath: " << p_path + "/content" << std::endl;

  Content content = Content(ctx, p_path + "/content");

  GenieView genieView = GenieView(screen, content);
  screen->draw_all();
  screen->set_visible(true);

  mainloop(1 / 60.f * 1000);

  nanogui::shutdown();

  return 0;
}
