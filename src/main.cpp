// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <genie/GenieView.hpp>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
// clang-format on

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
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
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  // Swap buffers
  glfwSwapBuffers(window);
}

int main() {
  glfwInit();
  GLFWwindow *window = glfwCreateWindow(800, 600, "ImGui + GLFW + GLAD Example",
                                        nullptr, nullptr);
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
