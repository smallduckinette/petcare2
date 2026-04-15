#include <memory>
#include <filesystem>
#include <iostream>

#include <boost/program_options.hpp>
#include <fmt/core.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "InputSubsystem.h"

namespace po = boost::program_options;

class Button
{
public:
  Button(const std::filesystem::path& file)
  {
    _texture.loadFromFile(file);
    _sprite.setTexture(_texture);
  }

  void place(sf::RenderWindow& window, float centerXpc, float topYpc, float scale)
  {
    float width = window.getSize().x * scale;
    float x = window.getSize().x * centerXpc - width / 2;
    float y = window.getSize().y * topYpc;
    float spriteScale = scale * window.getSize().x / _texture.getSize().x;

    _sprite.setPosition(sf::Vector2f(x, y));
    _sprite.setScale(sf::Vector2f(spriteScale, spriteScale));
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

    InputSubsystem inputSubsystem;

    std::map<std::filesystem::path, std::filesystem::path> data =
      {
        {"resources/bird.png", "resources/bird_stuff.png"},
        {"resources/cat.png", "resources/cat_stuff.png"},
        {"resources/dog.png", "resources/dog_stuff.png"},
        {"resources/duck.png", "resources/duck_stuff.png"},
        {"resources/turtle.png", "resources/turtle_stuff.png"}
      };

    sf::RenderWindow window(chosenMode, "Petcare", mode);
    window.setVerticalSyncEnabled(true);

    Button button("resources/duck.png");
    button.place(window, 0.5, 0.075, 0.25);

    std::vector<std::unique_ptr<Button>> buttons;
    for (const auto& [key, value] : data)
    {
      buttons.push_back(std::make_unique<Button>(value));
      buttons.back()->place(window, 1.0f * buttons.size() / (data.size() + 1), 0.5, 1.0f / (data.size() + 2));
    }

    inputSubsystem.onQuit().connect([&]() { window.close(); });
    inputSubsystem.onCancel().connect([&]() { window.close(); });
    inputSubsystem.onLeft().connect([&]() { fmt::print("Left\n"); });
    inputSubsystem.onRight().connect([&]() { fmt::print("Right\n"); });

    while (window.isOpen())
    {
      inputSubsystem.run(window);

      window.clear();

      button.draw(window);
      for(auto& button : buttons)
      {
        button->draw(window);
      }

      window.display();
    }

    fmt::print("Closing\n");
  }

  return 0;
}
