#pragma once

#include <SFML/Graphics.hpp>

#include "Signal.h"

class InputSubsystem
{
public:
  InputSubsystem(sf::RenderWindow* window);

  void run();

  Signal<>& onAccept();
  Signal<>& onCancel();
  Signal<>& onLeft();
  Signal<>& onRight();
  Signal<>& onQuit();

private:
  Signal<> _accept;
  Signal<> _cancel;
  Signal<> _left;
  Signal<> _right;
  Signal<> _quit;

  const std::map<sf::Keyboard::Key, Signal<>*> _eventMap;
  const std::map<unsigned int, Signal<>*> _joyMap;
  sf::RenderWindow* _window;
};
