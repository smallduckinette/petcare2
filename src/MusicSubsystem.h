#pragma once

#include <SFML/Audio.hpp>

#include "Config.h"

class MusicSubsystem
{
public:
  MusicSubsystem();

  void load(config::Config& conf);

  void run();

private:
  std::vector<std::filesystem::path> _playlist;
  size_t _current;

  sf::Music _music;
};
