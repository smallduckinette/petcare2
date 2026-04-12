#include <memory>
#include <filesystem>
#include <fmt/core.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Button
{
public:
  Button(const std::filesystem::path& file,
         int x,
         int y)
  {
    _texture.loadFromFile(file);
    _sprite.setTexture(_texture);
  }

  void draw(sf::RenderWindow& window)
  {
    window.draw(_sprite);
  }

private:
  sf::Texture _texture;
  sf::Sprite _sprite;
};

int main()
{
  fmt::print("Starting Petcare\n");

  sf::RenderWindow window(sf::VideoMode(800, 600), "Petcare");
  window.setVerticalSyncEnabled(true);

  Button button("resources/duck.png", 100, 100);

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

    button.draw(window);

    window.display();
  }

  fmt::print("Closing\n");

  return 0;
}
