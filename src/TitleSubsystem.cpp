#include "TitleSubsystem.h"

#include <ranges>

#include "Visual.h"

TitleSubsystem::TitleSubsystem(sf::RenderWindow* window):
  _window(window)
{
}

TitleSubsystem::~TitleSubsystem() = default;

void TitleSubsystem::load(const config::Config& conf)
{
  _textures = conf._textures | std::views::transform([](const auto& item) { auto [key, value] = item; auto texture = std::make_unique<sf::Texture>(); texture->loadFromFile(value); return std::make_pair(key, std::move(texture)); }) | std::ranges::to<std::map>();

  // Title
  auto title = makeVisual(conf._title);
  title->place(_window, 0.5, 0.05, 0.45);
  title->setStyle(normalStyle);
}

void TitleSubsystem::run() const
{
  std::ranges::for_each(_visuals, [&](const auto& visual) { visual.second->draw(_window); });
}

sf::Texture* TitleSubsystem::getTexture(TextureID textureID) const
{
  auto it = _textures.find(textureID);
  if (it == _textures.end())
  {
    throw std::runtime_error("Cannot find texture");
  }
  else
  {
    return it->second.get();
  }
}

Visual* TitleSubsystem::makeVisual(const config::Entity& entity)
{
  return _visuals.emplace(entity._entityID, std::make_unique<Visual>(entity, [&](TextureID textureID) { return getTexture(textureID); })).first->second.get();
}
