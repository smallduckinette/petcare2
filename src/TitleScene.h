#pragma once

#include <SFML/Window.hpp>

#include "Config.h"
#include "GraphicsSubsystem.h"
#include "InputSubsystem.h"
#include "Scene.h"
#include "TitleSubsystem.h"

class TextureCache;

class TitleScene : public Scene
{
public:
  TitleScene(const config::Config& conf,
             sf::RenderWindow* window,
             TextureCache* textureCache);

  void run() override;

  Signal<>& onStart();
  Signal<>& onQuit();

private:
  sf::RenderWindow* _window;

  InputSubsystem _inputSubsystem;
  TitleSubsystem _titleSubsystem;

  Signal<> _start;
  Signal<> _quit;
};
