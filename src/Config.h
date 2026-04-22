#pragma once

#include <filesystem>
#include <vector>
#include <map>

#include "Constants.h"

namespace config
{
  struct Texture
  {
    TextureID _textureID;
    std::filesystem::path _filename;
  };

  struct Sound
  {
    EntityID _entityID;
    std::filesystem::path _filename;
  };

  struct Entity
  {
    EntityID _entityID;
    TextureID _textureID;
    std::map<StyleID, TextureID> _styles;
  };

  struct Config
  {
    std::vector<Texture> _textures;
    std::vector<Entity> _animals;
    std::vector<Entity> _accessories;
    std::vector<Sound> _sounds;
  };

  Config makeConfig();
}
