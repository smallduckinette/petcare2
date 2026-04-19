#pragma once

#include <filesystem>
#include <vector>

#include "Constants.h"

namespace config
{
  struct Texture
  {
    TextureID _textureID;
    std::filesystem::path _filename;
  };

  struct Entity
  {
    EntityID _entityID;
    TextureID _textureID;
  };

  struct Config
  {
    std::vector<Texture> _textures;
    std::vector<Entity> _accessories;
  };

  Config makeConfig();
}
