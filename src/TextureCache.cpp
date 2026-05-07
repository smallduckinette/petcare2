#include "TextureCache.h"

#include <ranges>


void TextureCache::load(const config::Config& conf)
{
  _textures = conf._textures | std::views::transform([](const auto& item) { auto [key, value] = item; auto texture = std::make_unique<sf::Texture>(); texture->loadFromFile(value); return std::make_pair(key, std::move(texture)); }) | std::ranges::to<std::map>();
}

sf::Texture* TextureCache::getTexture(TextureID textureID) const
{
  auto it = _textures.find(textureID);
  if (it == _textures.end())
  {
    throw std::runtime_error("Cannot find texture");
  }
  else
  {
    return it->second.get();
  }
}
