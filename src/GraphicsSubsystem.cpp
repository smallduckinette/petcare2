#include "GraphicsSubsystem.h"

#include <ranges>
#include <filesystem>

#include "Visual.h"

GraphicsSubsystem::GraphicsSubsystem(sf::RenderWindow* window):
  _window(window)
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

void GraphicsSubsystem::load(config::Config& conf)
{
  _textures = conf._textures | std::views::transform([](const auto& item) { auto [key, value] = item; auto texture = std::make_unique<sf::Texture>(); texture->loadFromFile(value); return std::make_pair(key, std::move(texture)); }) | std::ranges::to<std::map>();

  const size_t accessoryCount = conf._accessories.size();
  for (const auto& [index, entity] : std::views::enumerate(conf._accessories))
  {
    auto styles = entity._styles | std::views::transform([&](const auto& item) { return std::make_pair(item.first, getTexture(item.second));}) | std::ranges::to<std::map>();

    auto visual = std::make_unique<Visual>(getTexture(entity._textureID), styles);
    visual->place(_window, 1.0f * (index + 1) / (accessoryCount + 1), 0.5, 1.0f / (accessoryCount + 2));
    visual->setStyle(normalStyle);
    _visuals.emplace(entity._entityID, std::move(visual));
  }
}

sf::Texture* GraphicsSubsystem::getTexture(TextureID textureID) const
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
