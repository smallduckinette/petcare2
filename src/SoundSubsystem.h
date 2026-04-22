#pragma once

#include <SFML/Audio.hpp>

#include "Config.h"

class SoundSubsystem
{
public:
  SoundSubsystem();

  void load(config::Config& conf);

  void play(EntityID entityID);

private:
  std::map<EntityID, sf::SoundBuffer> _soundBuffers;

  std::vector<sf::Sound> _sounds;
  size_t _soundIndex;
};
