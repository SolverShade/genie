// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <genie/GenieView.hpp>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>
#include <ostream>
// clang-format on

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

/**
 * Sets up glfw related settings that must be run
 * before a window is created such as window transparency
 * and other such things
 */
void preWindowCreationSetup() {
  glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, 1);
}

void initImGui(GLFWwindow *window) {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  (void)io;

  ImGui::StyleColorsDark();

  ImGui_ImplGlfw_InitForOpenGL(window, true);
  ImGui_ImplOpenGL3_Init("#version 330");
}

void update(GLFWwindow *window) {
  glfwPollEvents();

  // Start a new ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  // ImGui content goes here
  ImGui::Begin("Hellos, ImGui!");
  ImGui::Text("This is a simple example of ImGui with GLFW and GLAD.");
  ImGui::End();

  // Render ImGui content
  ImGui::Render();
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  // Swap buffers
  glfwSwapBuffers(window);
}

int main() {
  if (!glfwInit()) {
    return -1;
  }

  preWindowCreationSetup();

  GLFWwindow *window = glfwCreateWindow(800, 600, "ImGui + GLFW + GLAD Example",
                                        nullptr, nullptr);

  if (window == nullptr) {
    std::cout << "failed to create window" << std::endl;
    return -1;
  }

  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  initImGui(window);

  GenieView genieView = GenieView(window);

  while (!glfwWindowShouldClose(window)) {
    update(window);
  }

  // Cleanup on exit
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  glfwDestroyWindow(window);
  glfwTerminate();

  return 0;
}
