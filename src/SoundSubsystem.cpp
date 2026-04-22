#include "SoundSubsystem.h"

#include <fmt/core.h>

SoundSubsystem::SoundSubsystem():
  _sounds(8),
  _soundIndex(0)
{
}

void SoundSubsystem::load(config::Config& conf)
{
  for (const auto& sound : conf._sounds)
  {
    _soundBuffers.emplace(sound._entityID, sf::SoundBuffer()).first->second.loadFromFile(sound._filename);
  }
}

void SoundSubsystem::play(EntityID entityID)
{
  auto it = _soundBuffers.find(entityID);
  if (it != _soundBuffers.end())
  {
    _sounds[_soundIndex].stop();
    _sounds[_soundIndex].setBuffer(it->second);
    _sounds[_soundIndex].play();
    _soundIndex = (_soundIndex + 1) % _sounds.size();

    fmt::print("Play\n");
  }
}
