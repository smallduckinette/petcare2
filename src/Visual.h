#pragma once

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Constants.h"

class Visual
{
public:
  Visual(sf::Texture* texture, const std::map<StyleID, sf::Texture*>& styles);

  void draw(sf::RenderWindow* window);

  void place(sf::RenderWindow* window, float centerXpc, float topYpc, float scale);

  void setStyle(const StyleID& style);
  void setVisibility(bool visibility);

private:
  void placeSprite(sf::RenderWindow* window, float centerXpc, float topYpc, float scale, sf::Texture* texture, sf::Sprite& sprite) const;

  sf::Texture* _texture;
  sf::Sprite _sprite;

  std::map<StyleID, std::pair<sf::Texture*, sf::Sprite>> _styles;
  sf::Sprite* _currentStyle;

  bool _visibility;
};
