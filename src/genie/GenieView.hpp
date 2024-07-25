// example.hpp
#ifndef GENIEVIEW_HPP
#define GENIEVIEW_HPP

#include "graphics/Content.hpp"
#include "nanogui/screen.h"
#include "nanogui/window.h"

class GenieView {
public:
  GenieView(nanogui::Screen *screen, Content content);

private:
  void setupScreenContent();
  void loadGenieWindow();
  void onGenieFocus();
  Content content;
  nanogui::Screen *screen;
  nanogui::Window *genieWindow;
};

#endif
