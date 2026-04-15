#include "InputSubsystem.h"


InputSubsystem::InputSubsystem():
  _eventMap(
    {
      {sf::Keyboard::Key::Enter, &_accept},
      {sf::Keyboard::Key::Escape, &_cancel},
      {sf::Keyboard::Key::Left, &_left},
      {sf::Keyboard::Key::Right, &_right}
    })
{
}

void InputSubsystem::run(sf::RenderWindow& window)
{
  sf::Event event;
  while (window.pollEvent(event))
  {
    if(event.type == sf::Event::Closed)
    {
      _quit.emit();
    }
    else if (event.type == sf::Event::KeyPressed || sf::Event::KeyReleased)
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
