#include "nanogui/theme.h"
#include <filesystem>
#include <genie/GenieView.hpp>
#include <graphics/Content.hpp>
#include <iostream>
#include <nanogui/nanogui.h>
#include <nanogui/screen.h>
#include <ostream>

using namespace nanogui;

std::string project_path =
    std::filesystem::current_path().parent_path().string();

void onGenieFocus() {}

void GenieView::loadGenieWindow() {
  genieWindow->set_position(Vector2i(30, 15));
  genieWindow->set_size(Vector2i(300, 300));

  ImageView *genieImageView = new ImageView(genieWindow);
  genieImageView->set_image(
      GenieView::content.LoadImageTexture("GeniePreview"));

  // genieImageView->set_background_color(Color(0, 0, 0, 255));
  // genieImageView->set_theme(Theme
  // Theme

  float scale = 5.0f;

  genieImageView->set_scale(scale);
  genieImageView->set_position(
      Vector2i(genieWindow->width() / 2, genieWindow->height() / 2));

  genieWindow->set_layout(new GroupLayout());
}

void GenieView::setupScreenContent() {
  // Set the screen's background color to be transparent (RGBA)
  screen->set_background(Color(0, 0, 0, 0));

  screen->perform_layout();
  screen->set_visible(true);
}

GenieView::GenieView(nanogui::Screen *screen, Content content)
    : screen(screen), content(content) {
  std::cout << "screen constructed" << std::endl;
  GenieView::genieWindow = new Window(screen, "genie demo");

  setupScreenContent();
  loadGenieWindow();
}
