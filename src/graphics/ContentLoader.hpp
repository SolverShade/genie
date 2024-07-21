#ifndef CONTENTLOADER_HPP
#define CONTENTLOADER_HPP

#include <map>
#include <memory>
#include <nanogui/common.h>
#include <string>

using namespace std;
using namespace nanogui;

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
  std::map<std::string, shared_ptr<Texture>>
  LoadTextures(NVGcontext *ctx, std::string contentPath);
};

#endif
