#pragma once

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Config.h"

class TextureCache;
class Visual;

class TitleSubsystem
{
public:
  TitleSubsystem(sf::RenderWindow* window, TextureCache* textureCache);
  ~TitleSubsystem();

  void load(const config::Config& conf);

  void run() const;

private:
  Visual* makeVisual(const config::Entity& entity);

  sf::RenderWindow* _window;
  TextureCache* _textureCache;

  std::map<EntityID, std::unique_ptr<Visual>> _visuals;
};
