#include "nanogui/texture.h"
#include <filesystem>
#include <genie/GenieView.hpp>
#include <iostream>
#include <nanogui/nanogui.h>
#include <nanogui/screen.h>
#include <ostream>

// Include stb_image.h
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace nanogui;

std::string project_path =
    std::filesystem::current_path().parent_path().string();

void onGenieFocus() {}

void GenieView::loadGenieWindow() {
  genieWindow->set_position(Vector2i(30, 15));
  genieWindow->set_size(Vector2i(300, 300));

  // Texture *genieTexture = new Texture(
  // project_path + "/content/GeniePreview.png",
  // Texture::InterpolationMode::Nearest, Texture::InterpolationMode::Nearest);
  //

  Texture *genieTexture =
      new Texture(Texture::PixelFormat::RGBA, Texture::ComponentFormat::UInt8,
                  Vector2i(46, 28), Texture::InterpolationMode::Nearest,
                  Texture::InterpolationMode::Nearest);

  int w, h, comp;
  unsigned char *genieImageData =
      stbi_load((project_path + ("/content/GeniePreview.png")).c_str(), &w, &h,
                &comp, STBI_rgb_alpha);

  std::cout << (project_path + ("/content/GeniePreview.png")).c_str()
            << std::endl;

  if (!genieImageData) {
    std::cerr << "Failed to load image! " << stbi_failure_reason() << std::endl;
  }

  genieTexture->upload(genieImageData);

  ImageView *genieImageView = new ImageView(genieWindow);
  genieImageView->set_image(genieTexture);

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

GenieView::GenieView(nanogui::Screen *screen) {
  std::cout << "screen constructed" << std::endl;
  GenieView::screen = screen;
  GenieView::genieWindow = new Window(screen, "genie demo");

  setupScreenContent();
  loadGenieWindow();
}
