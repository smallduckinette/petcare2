#include "TitleSubsystem.h"

#include <ranges>

#include "TextureCache.h"
#include "Visual.h"

TitleSubsystem::TitleSubsystem(sf::RenderWindow* window, TextureCache* textureCache):
  _window(window),
  _textureCache(textureCache)
{
}

TitleSubsystem::~TitleSubsystem() = default;

void TitleSubsystem::load(const config::Config& conf)
{
  // Title
  auto title = makeVisual(conf._title);
  title->place(_window, 0.5, 0.05, 0.45);
  title->setStyle(normalStyle);
}

void TitleSubsystem::run() const
{
  std::ranges::for_each(_visuals, [&](const auto& visual) { visual.second->draw(_window); });
}

Visual* TitleSubsystem::makeVisual(const config::Entity& entity)
{
  return _visuals.emplace(entity._entityID, std::make_unique<Visual>(entity, [&](TextureID textureID) { return _textureCache->getTexture(textureID); })).first->second.get();
}
