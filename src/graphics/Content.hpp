#ifndef CONTENTLOADER_HPP
#define CONTENTLOADER_HPP

#include <map>
#include <nanogui/common.h>
#include <string>

using namespace std;
using namespace nanogui;

/**
 * Loads content of various file types such as images and textures. Upon
 * creation all files are stored as maps with thier corresponding names and
 * files.
 *
 * @param 'NVGcontext' the nanogui screen context
 * @param 'the path where all files to be loaded are present'
 */
class Content {
public:
  Content(NVGcontext *ctx, string contentPath);

  /**
   * returns the texture from the given image file, these are typically used for
   * nanogui displaying images.
   *
   * @param 'fileName' name of file to load texture from
   */
  Texture *LoadImageTexture(string fileName);

private:
  map<std::string, Texture *> imagesMap;
};

#endif
