#pragma once

#include <SFML/Window.hpp>

#include "Config.h"
#include "GameplaySubsystem.h"
#include "GraphicsSubsystem.h"
#include "HudSubsystem.h"
#include "InputSubsystem.h"
#include "SoundSubsystem.h"

class MainLoop
{
public:
  MainLoop(const config::Config& conf,
           sf::RenderWindow* window,
           SoundSubsystem* soundSubsystem);

  void run();

private:
  sf::RenderWindow* _window;

  SoundSubsystem* _soundSubsystem;
  GraphicsSubsystem _graphicsSubsystem;
  InputSubsystem _inputSubsystem;
  GameplaySubsystem _gameplaySubsystem;
  HudSubsystem _hudSubsystem;
};
