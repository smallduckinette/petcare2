#pragma once

#include <SFML/Graphics.hpp>

#include <map>
#include <memory>

#include "Constants.h"
#include "Config.h"

class TextureCache
{
public:
  void load(const config::Config& conf);

  sf::Texture* getTexture(TextureID textureID) const;

private:
  std::map<TextureID, std::unique_ptr<sf::Texture>> _textures;
};
