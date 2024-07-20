#include <graphics/ContentLoader.hpp>
#include <iostream>
#include <memory>
#include <nanogui/common.h>
#include <nanogui/texture.h>
#include <nanogui/vector.h>
#include <utility> // for std::pair

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

ContentLoader::ContentLoader() { cout << "created content loader" << endl; }

map<string, Texture> ContentLoader::LoadTextures(NVGcontext *ctx,
                                                 string contentPath) {
  map<string, Texture> textureMap;
  std::vector<std::pair<int, std::string>> imageInfos;

  try {
    imageInfos = load_image_directory(ctx, contentPath);
  } catch (const std::exception &e) {
    std::cerr << "Warning: " << e.what() << std::endl;
  }

  using ImageHolder = std::unique_ptr<uint8_t[], void (*)(void *)>;
  vector<std::pair<Texture, ImageHolder>> m_images;

  // Create a Texture instance for each object
  for (auto &imageInfo : imageInfos) {
    Vector2i size;
    int n = 0;
    ImageHolder texture_data(stbi_load((imageInfo.second + ".png").c_str(),
                                       &size.x(), &size.y(), &n, 0),
                             stbi_image_free);
    assert(n == 4);

    Texture tex =
        Texture(Texture::PixelFormat::RGBA, Texture::ComponentFormat::UInt8,
                size, Texture::InterpolationMode::Trilinear,
                Texture::InterpolationMode::Nearest);

    tex.upload(texture_data.get());
    // textureMap[imageInfo.second] = tex;
    m_images.emplace_back(tex, std::move(texture_data));
    cout << imageInfo.second << endl;
  }

  return textureMap;
}
