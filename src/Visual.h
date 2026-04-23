#pragma once

#include <map>
#include <memory>
#include <functional>

#include <SFML/Graphics.hpp>

#include "Config.h"

class Visual
{
public:
  Visual(const config::Entity& entity, std::function<sf::Texture*(TextureID textureID)> getTexture);

  void draw(sf::RenderWindow* window);

  void place(sf::RenderWindow* window, float centerXpc, float topYpc, float scale);

  void setStyle(const StyleID& style);
  void setVisibility(bool visibility);

private:
  class Element
  {
  public:
    Element(sf::Texture* texture, config::Animation animation);

    void draw(sf::RenderWindow* window);

    void place(sf::RenderWindow* window, float centerXpc, float topYpc, float scale);

  private:
    sf::Texture* _texture;
    sf::Sprite _sprite;
    config::Animation _animation;
  };

  void placeSprite(sf::RenderWindow* window, float centerXpc, float topYpc, float scale, sf::Texture* texture, sf::Sprite& sprite) const;

    //sf::Texture* _texture;
    //sf::Sprite _sprite;

    //std::map<StyleID, std::pair::Texture*, sf::Sprite>> _styles;
    //sf::Sprite* _currentStyle;

  using StylesT = std::map<StyleID, std::vector<std::unique_ptr<Element>>>;
  StylesT _styles;
  StylesT::iterator _currentStyle;


  bool _visibility;
};
