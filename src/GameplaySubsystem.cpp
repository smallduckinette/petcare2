#include "GameplaySubsystem.h"

#include <ranges>

void GameplaySubsystem::load(config::Config& conf)
{
  _buttons = conf._accessories | std::views::transform([](const auto& item) { return item._entityID;}) | std::ranges::to<std::vector>();
}

void GameplaySubsystem::next()
{
  moveSelection(1);
}

void GameplaySubsystem::previous()
{
  moveSelection(-1);
}

void GameplaySubsystem::moveSelection(int movement)
{
  if (!_buttons.empty())
  {
    if (_currentSelection)
    {
      _deselect.emit(_buttons[*_currentSelection]);
      _deselect.reset();
    }

    _currentSelection = (_currentSelection.value_or(_buttons.size() - 1) + _buttons.size() + movement) % _buttons.size();
    _select.emit(_buttons[*_currentSelection]);
    _select.reset();
  }
}

Signal<EntityID>& GameplaySubsystem::onSelect()
{
  return _select;
}

Signal<EntityID>& GameplaySubsystem::onDeselect()
{
  return _deselect;
}
