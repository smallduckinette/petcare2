#include "MusicSubsystem.h"

#include <ranges>
#include <random>

#include <fmt/core.h>

MusicSubsystem::MusicSubsystem():
  _current(0)
{
}

void MusicSubsystem::load(config::Config& conf)
{
  // Create the playlist
  _playlist = conf._playlist | std::views::transform([](const auto& music) { return music._filename; }) | std::ranges::to<std::vector>();

  // Shuffle it
  std::random_device rd;
  std::mt19937 rand(rd());
  std::shuffle(_playlist.begin(), _playlist.end(), rand);
}

void MusicSubsystem::run()
{
  if (_music.getStatus() == sf::SoundSource::Status::Stopped)
  {
    _music.openFromFile(_playlist[_current]);
    _music.play();
    _music.setVolume(50);
    _current = (_current + 1) % _playlist.size();
  }
}
