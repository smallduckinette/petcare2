#include "GameplaySubsystem.h"

#include <ranges>

#include <fmt/core.h>

GameplaySubsystem::GameplaySubsystem():
  _rand(std::chrono::steady_clock::now().time_since_epoch().count())
{
}

void GameplaySubsystem::load(config::Config& conf)
{
  _buttons = conf._accessories | std::views::transform([](const auto& item) { return item._entityID;}) | std::ranges::to<std::vector>();
  _animals = conf._animals | std::views::transform([](const auto& item) { return item._entityID;}) | std::ranges::to<std::vector>();
}

void GameplaySubsystem::next()
{
  moveSelection(1);
}

void GameplaySubsystem::previous()
{
  moveSelection(-1);
}

void GameplaySubsystem::select()
{
  if (_currentAnimal && _currentSelection)
  {
    if (*_currentAnimal == *_currentSelection)
    {
      fmt::print("Bravo\n");
    }
    else
    {
      fmt::print("Booo\n");
    }
  }
  startGame();
}

void GameplaySubsystem::startGame()
{
  // If we were showing something, hide it
  if (_currentAnimal)
  {
    _hide.fire(_animals[*_currentAnimal]);
  }
  _currentAnimal = selectRandomAnimal();
  _show.fire(_animals[*_currentAnimal]);
}

void GameplaySubsystem::moveSelection(int movement)
{
  if (!_buttons.empty())
  {
    if (_currentSelection)
    {
      _deselect.fire(_buttons[*_currentSelection]);
    }

    _currentSelection = (_currentSelection.value_or(_buttons.size() - 1) + _buttons.size() + movement) % _buttons.size();
    _select.fire(_buttons[*_currentSelection]);
  }
}

size_t GameplaySubsystem::selectRandomAnimal()
{
  return std::uniform_int_distribution<size_t>(0, _animals.size() - 1)(_rand);
}

Signal<EntityID>& GameplaySubsystem::onSelect()
{
  return _select;
}

Signal<EntityID>& GameplaySubsystem::onDeselect()
{
  return _deselect;
}

Signal<EntityID>& GameplaySubsystem::onShow()
{
  return _show;
}

Signal<EntityID>& GameplaySubsystem::onHide()
{
  return _hide;
}
