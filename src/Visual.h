#pragma once

#include <SFML/Graphics.hpp>

class Visual
{
public:
  Visual(sf::Texture* texture);

  void draw(sf::RenderWindow* window);

  void place(sf::RenderWindow* window, float centerXpc, float topYpc, float scale);

private:
  sf::Texture* _texture;
  sf::Sprite _sprite;
};
