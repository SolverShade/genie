// example.hpp
#ifndef GENIEVIEW_HPP
#define GENIEVIEW_HPP

#include "nanogui/screen.h"

class GenieView {
public:
  GenieView(nanogui::Screen *screen);

private:
  void setupScreenContent();
  nanogui::Screen *screen;
};

#endif
