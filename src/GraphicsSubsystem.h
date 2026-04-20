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

  void load(config::Config& conf);

  void run() const;

private:
  sf::Texture* getTexture(TextureID textureID) const;

  sf::RenderWindow* _window;

  std::map<TextureID, std::unique_ptr<sf::Texture>> _textures;
  std::map<EntityID, std::unique_ptr<Visual>> _visuals;
};
