#include "Visual.h"

#include <fmt/core.h>

Visual::Visual(sf::Texture* texture):
  _texture(texture)
{
  _sprite.setTexture(*texture);
}

void Visual::draw(sf::RenderWindow* window)
{
  window->draw(_sprite);
}

void Visual::place(sf::RenderWindow* window, float centerXpc, float topYpc, float scale)
{
  float width = window->getSize().x * scale;
  float x = window->getSize().x * centerXpc - width / 2;
  float y = window->getSize().y * topYpc;
  float spriteScale = scale * window->getSize().x / _texture->getSize().x;

  _sprite.setPosition(sf::Vector2f(x, y));
  _sprite.setScale(sf::Vector2f(spriteScale, spriteScale));

  fmt::print("{} {} {}\n", x, y, spriteScale);
}
