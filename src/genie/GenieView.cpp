#include "nanogui/texture.h"
#include <filesystem>
#include <genie/GenieView.hpp>
#include <iostream>
#include <nanogui/nanogui.h>
#include <nanogui/screen.h>
#include <ostream>

using namespace nanogui;

void onGenieFocus() {}

void GenieView::setupScreenContent() {
  // Set the screen's background color to be transparent (RGBA)
  screen->set_background(Color(0, 0, 0, 0));

  nanogui::Window *window = new Window(screen, "genie demo");
  window->set_position(Vector2i(30, 15));
  window->set_layout(new GroupLayout());
  window->set_size(Vector2i(300, 300));

  Button *button = new Button(window, "Click me!");
  button->set_callback([]() { std::cout << "Button clicked!" << std::endl; });

  std::string project_path =
      std::filesystem::current_path().parent_path().string();

  std::cout << "Current Path: " << project_path << std::endl;

  Texture *genieTexture = new Texture(
      project_path + "/content/GeniePreview.png",
      Texture::InterpolationMode::Nearest, Texture::InterpolationMode::Nearest);

  ImageView *imageView = new ImageView(window);
  imageView->set_image(genieTexture);

  float scale = 5.0f;
  imageView->set_scale(scale);

  imageView->set_position(Vector2i(window->width() / 2, window->height() / 2));

  screen->perform_layout();
  screen->set_visible(true);
}

GenieView::GenieView(nanogui::Screen *screen) {
  std::cout << "screen constructed" << std::endl;
  GenieView::screen = screen;

  setupScreenContent();
}
