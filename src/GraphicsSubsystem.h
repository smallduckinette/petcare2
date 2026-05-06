#pragma once

#include <map>
#include <set>
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Config.h"

class Visual;

class GraphicsSubsystem
{
public:
  GraphicsSubsystem(sf::RenderWindow* window);
  ~GraphicsSubsystem();

  void load(const config::Config& conf);

  void run() const;

  void setStyle(EntityID entity, const StyleID& style);
  void setVisibility(EntityID entity, bool visible);

private:
  sf::Texture* getTexture(TextureID textureID) const;
  Visual* makeVisual(const config::Entity& entity);

  sf::RenderWindow* _window;

  std::map<TextureID, std::unique_ptr<sf::Texture>> _textures;
  std::map<EntityID, std::unique_ptr<Visual>> _visuals;
};
