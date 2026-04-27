#include "HudSubsystem.h"

#include <fmt/core.h>

HudSubsystem::HudSubsystem(sf::RenderWindow* window):
  _window(window),
  _score(0),
  _misses(0)
{
  const int fontSize = 0.2 * window->getSize().y;
  const int posX = 0.05 * window->getSize().x;
  const int posY = 0.05 * window->getSize().y;

  _font.loadFromFile("resources/Youre Gone.otf");
  _text.setFont(_font);
  _text.setCharacterSize(fontSize);
  _text.setPosition(posX, posY);
  _text.setFillColor(sf::Color(255, 0, 0));
  _text.setOutlineColor(sf::Color(255, 255, 0));
  _text.setOutlineThickness(20);
  update();
}

void HudSubsystem::increaseScore()
{
  ++_score;
  update();
}

void HudSubsystem::increaseMisses()
{
  ++_misses;
  update();
}

void HudSubsystem::run()
{
  _window->draw(_text);
}

void HudSubsystem::update()
{
  _text.setString(fmt::format("{}/{}", _score, _score + _misses));
}
