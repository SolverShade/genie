#include <graphics/ContentLoader.hpp>
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

ContentLoader::ContentLoader() { cout << "created content loader" << endl; }

map<string, shared_ptr<Texture>>
ContentLoader::LoadTextures(NVGcontext *ctx, string contentPath) {
  map<string, shared_ptr<Texture>> textureMap;
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

    shared_ptr<Texture> tex = make_shared<Texture>(
        Texture::PixelFormat::RGBA, Texture::ComponentFormat::UInt8, size,
        Texture::InterpolationMode::Trilinear,
        Texture::InterpolationMode::Nearest);

    tex->upload(texture_data.get());
    string textureName = TextParsing::GetFileName(imageInfo.second);
    textureMap[textureName] = tex;

    cout << "path: " << imageInfo.second << endl;
    cout << "name: " << textureName << endl;
  }

  return textureMap;
}
