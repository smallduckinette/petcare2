#pragma once

#include <map>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Constants.h"
#include "Config.h"

class Visual;

class TitleSubsystem
{
public:
  TitleSubsystem(sf::RenderWindow* window);
  ~TitleSubsystem();

  void load(const config::Config& conf);

  void run() const;

private:
  sf::Texture* getTexture(TextureID textureID) const;
  Visual* makeVisual(const config::Entity& entity);

  sf::RenderWindow* _window;

  std::map<TextureID, std::unique_ptr<sf::Texture>> _textures;
  std::map<EntityID, std::unique_ptr<Visual>> _visuals;
};
