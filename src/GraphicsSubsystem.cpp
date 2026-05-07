#include "GraphicsSubsystem.h"

#include <ranges>

#include "TextureCache.h"
#include "Visual.h"

GraphicsSubsystem::GraphicsSubsystem(sf::RenderWindow* window, TextureCache* textureCache):
  _window(window),
  _textureCache(textureCache)
{
}

GraphicsSubsystem::~GraphicsSubsystem() = default;

void GraphicsSubsystem::run() const
{
  std::ranges::for_each(_visuals, [&](const auto& visual) { visual.second->draw(_window); });
}

void GraphicsSubsystem::setStyle(EntityID entity, const StyleID& style)
{
  auto it = _visuals.find(entity);
  if (it != _visuals.end())
  {
    it->second->setStyle(style);
  }
}

void GraphicsSubsystem::setVisibility(EntityID entity, bool visible)
{
  auto it = _visuals.find(entity);
  if (it != _visuals.end())
  {
    it->second->setVisibility(visible);
  }
}

void GraphicsSubsystem::load(const config::Config& conf)
{
  // Accessories
  const size_t accessoryCount = conf._accessories.size();
  for (const auto& [index, entity] : std::views::enumerate(conf._accessories))
  {
    auto visual = makeVisual(entity);
    visual->place(_window, 1.0f * (index + 1) / (accessoryCount + 1), 0.6, 1.0f / (accessoryCount + 2));
    visual->setStyle(normalStyle);
  }

  // Animals
  for (const auto& entity : conf._animals)
  {
    auto visual = makeVisual(entity);
    visual->place(_window, 0.5, 0.05, 0.3);
    visual->setVisibility(false);
    visual->setStyle(normalStyle);
  }
}

Visual* GraphicsSubsystem::makeVisual(const config::Entity& entity)
{
  return _visuals.emplace(entity._entityID, std::make_unique<Visual>(entity, [&](TextureID textureID) { return _textureCache->getTexture(textureID); })).first->second.get();
}
