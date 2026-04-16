#pragma once

#include <map>
#include <set>
#include <string>
#include <memory>

#include <SFML/Graphics.hpp>

#include "Constants.h"

class Displayable;

class GraphicsSubsystem
{
public:
  GraphicsSubsystem();

  void run(sf::RenderWindow& window) const;

  void registerDisplayable(Displayable* displayable);
  void deregisterDisplayable(Displayable* displayable);

private:
  std::map<TextureID, std::unique_ptr<sf::Texture>> loadTextures() const;

  const std::map<TextureID, std::unique_ptr<sf::Texture>> _textures;
  std::set<Displayable*> _displayables;
};
