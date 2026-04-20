#include <memory>
#include <filesystem>
#include <iostream>

#include <boost/program_options.hpp>
#include <fmt/core.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Config.h"
#include "GraphicsSubsystem.h"
#include "InputSubsystem.h"

namespace po = boost::program_options;


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

    auto conf = config::makeConfig();

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

    GraphicsSubsystem graphicsSubsystem(&window);
    InputSubsystem inputSubsystem(&window);

    graphicsSubsystem.load(conf);

    inputSubsystem.onQuit().connect([&]() { window.close(); });
    inputSubsystem.onCancel().connect([&]() { window.close(); });
    inputSubsystem.onLeft().connect([&]() { fmt::print("Left\n"); });
    inputSubsystem.onRight().connect([&]() { fmt::print("Right\n"); });

    while (window.isOpen())
    {
      inputSubsystem.run();

      window.clear();

      graphicsSubsystem.run();

      window.display();
    }

    fmt::print("Closing\n");
  }

  return 0;
}
