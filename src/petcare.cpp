#include <memory>
#include <fmt/core.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
  fmt::print("Starting Petcare\n");

  sf::RenderWindow window(sf::VideoMode(800, 600), "BricABrac");
  window.setVerticalSyncEnabled(true);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }
    }
    window.clear();
    window.display();
  }

  fmt::print("Closing\n");

  return 0;
}
