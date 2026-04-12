#include <memory>
#include <filesystem>
#include <iostream>

#include <boost/program_options.hpp>
#include <fmt/core.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace po = boost::program_options;

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

int main(int argc, char** argv)
{
  bool fullScreen = false;

  po::options_description desc("Options");
  desc.add_options()
    ("help,h", "display this help message")
    ("fs", po::bool_switch(&fullScreen)->default_value(false), "Full screen display");

  po::variables_map vm;
  po::store
    (po::parse_command_line(argc, argv, desc),
     vm);
  po::notify(vm);

  if(vm.count("help"))
  {
    std::cout << desc << std::endl;
  }
  else
  {
    fmt::print("Starting Petcare\n");

    sf::VideoMode chosenMode;
    uint32_t mode = 0;

    if (fullScreen)
    {
      auto availableModes = sf::VideoMode::getFullscreenModes();
      if (availableModes.empty())
      {
        throw std::runtime_error("No full screen video mode available");
      }
      chosenMode = availableModes.front();
      mode = sf::Style::Fullscreen;
    }
    else
    {
      chosenMode = sf::VideoMode(800, 600);
      mode = sf::Style::Default;
    }

    sf::RenderWindow window(chosenMode, "Petcare", mode);
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
  }

  return 0;
}
