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

  struct Music
  {
    std::filesystem::path _filename;
  };

  using Animation = std::variant<std::monostate, float>;

  struct Element
  {
    TextureID _textureID;
    Animation _animation;
  };

  struct Entity
  {
    EntityID _entityID;
    std::map<StyleID, std::vector<Element>> _styles;
  };

  struct Config
  {
    std::vector<Texture> _textures;
    std::vector<Entity> _animals;
    std::vector<Entity> _accessories;
    std::vector<Sound> _sounds;
    std::vector<Music> _playlist;
    Entity _title;
  };

  Config makeConfig();
}
