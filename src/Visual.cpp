#include "Visual.h"

#include <ranges>
#include <variant>
#include <cmath>

#include <fmt/core.h>

Visual::Visual(const config::Entity& entity, std::function<sf::Texture*(TextureID textureID)> getTexture):
  _visibility(true),
  _currentStyle(_styles.end())
{
  for (const auto& [style, elementsConfig] : entity._styles)
  {
    std::vector<std::unique_ptr<Element>> elements;
    for (const auto& elementConfig : elementsConfig)
    {
      auto texture = getTexture(elementConfig._textureID);
      if (texture)
      {
        elements.push_back(std::make_unique<Element>(texture, elementConfig._animation));
      }
    }
    _styles.emplace(style, std::move(elements));
  }
}

void Visual::draw(sf::RenderWindow* window)
{
  if (_visibility)
  {
    if (_currentStyle != _styles.end())
    {
      for (const auto& element : _currentStyle->second)
      {
        element->draw(window);
      }
    }
  }
}

void Visual::setStyle(const StyleID& style)
{
  _currentStyle = _styles.find(style);

  for (const auto& element : _currentStyle->second)
  {
    element->onPrepareDisplay();
  }
}

void Visual::setVisibility(bool visibility)
{
  _visibility = visibility;
}

void Visual::place(sf::RenderWindow* window, float centerXpc, float topYpc, float scale)
{
  std::ranges::for_each(_styles, [&](auto& style)
  {
    std::ranges::for_each(style.second, [&](auto& element)
    {
      element->place(window, centerXpc, topYpc, scale);
    });
  });
}

Visual::Element::Element(sf::Texture* texture, config::Animation animation):
  _texture(texture),
  _animation(animation)
{
  _sprite.setTexture(*_texture);
}

void Visual::Element::draw(sf::RenderWindow* window)
{
  std::visit([&](const auto& val) { animate(val); }, _animation);

  window->draw(_sprite);
}

void Visual::Element::place(sf::RenderWindow* window, float centerXpc, float topYpc, float scale)
{
  float width = window->getSize().x * scale;
  float x = window->getSize().x * centerXpc - width / 2;
  float y = window->getSize().y * topYpc;
  float spriteScale = scale * window->getSize().x / _texture->getSize().x;

  _sprite.setPosition(sf::Vector2f(x, y));
  _sprite.setScale(sf::Vector2f(spriteScale, spriteScale));
}

void Visual::Element::onPrepareDisplay()
{
  _clock.restart();
}

void Visual::Element::animate(std::monostate)
{
  // Noop
}

void Visual::Element::animate(double period)
{
  float color = std::cos(_clock.getElapsedTime().asSeconds() * std::numbers::pi / period) / 10 + 0.9;
  _sprite.setColor(sf::Color(255, 255, 255, 255 * color));
}
