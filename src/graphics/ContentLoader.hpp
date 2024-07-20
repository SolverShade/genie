#ifndef CONTENTLOADER_HPP
#define CONTENTLOADER_HPP

#include <map>
#include <nanogui/common.h>
#include <string>

class ContentLoader {
public:
  ContentLoader();

  /**
   * Create a dictionary of textures that are accessible by name. Textures are
   * commonly used to display images. note that this function also uploads GL
   * textures to the gpu
   *
   * @param 'contentPath' path to directory where images are stored.
   * @return Dictonary of name keys and texture values
   */
  std::map<std::string, nanogui::Texture> LoadTextures(NVGcontext *ctx,
                                                       std::string contentPath);
};

#endif
