#pragma once

#include <vector>
#include <optional>
#include <random>

#include "Config.h"
#include "Constants.h"
#include "Signal.h"

class GameplaySubsystem
{
public:
  GameplaySubsystem();

  void load(const config::Config& conf);
  void startGame();

  void next();
  void previous();
  void select();

  Signal<EntityID>& onSelect();
  Signal<EntityID>& onDeselect();
  Signal<EntityID>& onShow();
  Signal<EntityID>& onHide();
  Signal<>& onScore();
  Signal<>& onMiss();

private:
  void moveSelection(int movement);
  size_t selectRandomAnimal();

  std::vector<EntityID> _buttons;
  std::vector<EntityID> _animals;
  std::optional<size_t> _currentSelection;
  std::optional<size_t> _currentAnimal;

  std::mt19937 _rand;

  Signal<EntityID> _select;
  Signal<EntityID> _deselect;
  Signal<EntityID> _show;
  Signal<EntityID> _hide;
  Signal<> _score;
  Signal<> _miss;
};
