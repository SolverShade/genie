// example.hpp
#ifndef GENIEVIEW_HPP
#define GENIEVIEW_HPP

#include "nanogui/screen.h"
#include "nanogui/window.h"

class GenieView {
public:
  GenieView(nanogui::Screen *screen);

private:
  void setupScreenContent();
  void loadGenieWindow();
  void onGenieFocus();
  nanogui::Screen *screen;
  nanogui::Window *genieWindow;
};

#endif
