#include "Visual.h"

#include <fmt/core.h>

Visual::Visual(sf::Texture* texture, const std::map<StyleID, sf::Texture*>& styles):
  _texture(texture)
{
  _sprite.setTexture(*texture);

  for (const auto& [style, texture] : styles)
  {
    _styles.emplace(style, std::make_pair(texture, sf::Sprite())).first->second.second.setTexture(*texture);
  }
}

void Visual::draw(sf::RenderWindow* window)
{
  window->draw(_sprite);
  if (_currentStyle)
  {
    window->draw(*_currentStyle);
  }
}

void Visual::setStyle(const StyleID& style)
{
  auto it = _styles.find(style);
  _currentStyle = (it != _styles.end()) ? &it->second.second : nullptr;
}

void Visual::place(sf::RenderWindow* window, float centerXpc, float topYpc, float scale)
{
  placeSprite(window, centerXpc, topYpc, scale, _texture, _sprite);
  std::ranges::for_each(_styles, [&](auto& item) { placeSprite(window, centerXpc, topYpc, scale, item.second.first, item.second.second); });
}

void Visual::placeSprite(sf::RenderWindow* window, float centerXpc, float topYpc, float scale, sf::Texture* texture, sf::Sprite& sprite) const
{
  float width = window->getSize().x * scale;
  float x = window->getSize().x * centerXpc - width / 2;
  float y = window->getSize().y * topYpc;
  float spriteScale = scale * window->getSize().x / texture->getSize().x;

  sprite.setPosition(sf::Vector2f(x, y));
  sprite.setScale(sf::Vector2f(spriteScale, spriteScale));
}
