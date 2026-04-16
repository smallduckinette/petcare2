#pragma once

#include <SFML/Graphics.hpp>

class Displayable
{
public:
  virtual ~Displayable() = default;

  virtual void draw(sf::RenderWindow& window) const = 0;
};
