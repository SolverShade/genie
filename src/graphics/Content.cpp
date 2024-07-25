#include <graphics/Content.hpp>
#include <iostream>
#include <memory>
#include <nanogui/common.h>
#include <nanogui/texture.h>
#include <nanogui/vector.h>
#include <utility> // for std::pair
#include <utillities/TextParsing.hpp>

#define STB_IMAGE_STATIC
#define STB_IMAGE_IMPLEMENTATION
#if defined(_MSC_VER)
#pragma warning(disable : 4505) // don't warn about dead code in stb_image.h
#elif defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include <stb_image.h>

using std::vector;
using namespace std;
using namespace nanogui;

Content::Content(NVGcontext *ctx, string contentPath) {
  vector<std::pair<int, std::string>> imageInfos;

  try {
    imageInfos = load_image_directory(ctx, contentPath);
  } catch (const std::exception &e) {
    std::cerr << "Warning: " << e.what() << std::endl;
  }

  using ImageHolder = unique_ptr<uint8_t[], void (*)(void *)>;
  vector<std::pair<Texture, ImageHolder>> m_images;

  // Create a Texture instance for each object
  for (auto &imageInfo : imageInfos) {
    Vector2i size;
    int n = 0;
    ImageHolder texture_data(stbi_load((imageInfo.second + ".png").c_str(),
                                       &size.x(), &size.y(), &n, 4),
                             stbi_image_free);
    assert(n == 4);

    Texture *tex =
        new Texture(Texture::PixelFormat::RGBA, Texture::ComponentFormat::UInt8,
                    size, Texture::InterpolationMode::Trilinear,
                    Texture::InterpolationMode::Nearest);

    tex->upload(texture_data.get());
    string textureName = TextParsing::GetFileName(imageInfo.second);
    Content::imagesMap[textureName] = tex;

    cout << "path: " << imageInfo.second << endl;
    cout << "name: " << textureName << endl;
  }
}

Texture *Content::LoadImageTexture(string fileName) {
  return Content::imagesMap[fileName];
}
