#include "GraphicsSubsystem.h"

#include <ranges>
#include <filesystem>

#include "Displayable.h"

GraphicsSubsystem::GraphicsSubsystem():
  _textures(loadTextures())
{
}

void GraphicsSubsystem::run(sf::RenderWindow& window) const
{
  std::ranges::for_each(_displayables, [&](const auto& displayable) { displayable->draw(window); });
}

void GraphicsSubsystem::registerDisplayable(Displayable* displayable)
{
  _displayables.insert(displayable);
}

void GraphicsSubsystem::deregisterDisplayable(Displayable* displayable)
{
  _displayables.erase(displayable);
}

std::map<TextureID, std::unique_ptr<sf::Texture>> GraphicsSubsystem::loadTextures() const
{
  std::map<TextureID, std::filesystem::path> texturesConfig = {
    {tex::BIRD, "resources/bird.png"},
    {tex::BIRD_STUFF, "resources/bird_stuff.png"},
    {tex::CAT, "resources/cat.png"},
    {tex::CAT_STUFF, "resources/cat_stuff.png"},
    {tex::DOG, "resources/dog.png"},
    {tex::DOG_STUFF, "resources/dog_stuff.png"},
    {tex::DUCK, "resources/duck.png"},
    {tex::DUCK_STUFF, "resources/duck_stuff.png"},
    {tex::TURTLE, "resources/turtle.png"},
    {tex::TURTLE_STUFF, "resources/turtle_stuff.png"}
  };

  return texturesConfig | std::views::transform([](const auto& item) -> std::pair<TextureID, std::unique_ptr<sf::Texture>> { auto [key, value] = item; auto texture = std::make_unique<sf::Texture>(); texture->loadFromFile(value); return std::make_pair(key, std::move(texture));}) | std::ranges::to<std::map>();
}
