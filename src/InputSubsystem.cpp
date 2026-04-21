#include "InputSubsystem.h"

#include <fmt/core.h>

InputSubsystem::InputSubsystem(sf::RenderWindow* window):
  _eventMap(
    {
      {sf::Keyboard::Key::Enter, &_accept},
      {sf::Keyboard::Key::Escape, &_cancel},
      {sf::Keyboard::Key::Left, &_left},
      {sf::Keyboard::Key::Right, &_right}
    }),
  _joyMap(
    {
      {0, &_accept},
      {1, &_cancel}
    }),
  _window(window)
{
}

void InputSubsystem::run()
{
  sf::Event event;
  while (_window->pollEvent(event))
  {
    if(event.type == sf::Event::Closed)
    {
      _quit.emit();
    }
    else if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased)
    {
      auto it = _eventMap.find(event.key.code);
      if (it != _eventMap.end())
      {
        if (event.type == sf::Event::KeyPressed)
        {
          it->second->emit();
        }
        else
        {
          it->second->reset();
        }
      }
    }
    else if (event.type == sf::Event::JoystickButtonPressed || event.type == sf::Event::JoystickButtonReleased)
    {
      auto it = _joyMap.find(event.joystickButton.button);
      if (it != _joyMap.end())
      {
        if (event.type == sf::Event::JoystickButtonPressed)
        {
          it->second->emit();
        }
        else
        {
          it->second->reset();
        }
      }
    }
    else if (event.type == sf::Event::JoystickMoved && event.joystickMove.axis == 0)
    {
      if (event.joystickMove.position > 90)
      {
        _right.emit();
      }
      else if (event.joystickMove.position < 20)
      {
        _right.reset();
      }
      if (event.joystickMove.position < -90)
      {
        _left.emit();
      }
      else if (event.joystickMove.position > -20)
      {
        _left.reset();
      }
    }
  }
}

Signal<>& InputSubsystem::onAccept()
{
  return _accept;
}

Signal<>& InputSubsystem::onCancel()
{
  return _cancel;
}

Signal<>& InputSubsystem::onLeft()
{
  return _left;
}

Signal<>& InputSubsystem::onRight()
{
  return _right;
}

Signal<>& InputSubsystem::onQuit()
{
  return _quit;
}
