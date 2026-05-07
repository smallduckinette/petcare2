#pragma once

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Config.h"

class TextureCache;
class Visual;

class GraphicsSubsystem
{
public:
  GraphicsSubsystem(sf::RenderWindow* window, TextureCache* textureCache);
  ~GraphicsSubsystem();

  void load(const config::Config& conf);

  void run() const;

  void setStyle(EntityID entity, const StyleID& style);
  void setVisibility(EntityID entity, bool visible);

private:
  Visual* makeVisual(const config::Entity& entity);

  sf::RenderWindow* _window;
  TextureCache* _textureCache;

  std::map<EntityID, std::unique_ptr<Visual>> _visuals;
};
