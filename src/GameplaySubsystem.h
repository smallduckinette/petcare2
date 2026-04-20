#pragma once

#include <vector>
#include <optional>

#include "Config.h"
#include "Constants.h"
#include "Signal.h"

class GameplaySubsystem
{
public:
  void load(config::Config& conf);

  void next();
  void previous();

  Signal<EntityID>& onSelect();
  Signal<EntityID>& onDeselect();

private:
  void moveSelection(int movement);

  std::vector<EntityID> _buttons;
  std::optional<size_t> _currentSelection;

  Signal<EntityID> _select;
  Signal<EntityID> _deselect;
};
