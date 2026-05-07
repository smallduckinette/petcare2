#include "MainLoop.h"


MainLoop::MainLoop(const config::Config& conf,
                   sf::RenderWindow* window,
                   SoundSubsystem* soundSubsystem,
                   TextureCache* textureCache):
  _window(window),
  _soundSubsystem(soundSubsystem),
  _graphicsSubsystem(window, textureCache),
  _inputSubsystem(window),
  _hudSubsystem(window)
{
  _graphicsSubsystem.load(conf);
  _gameplaySubsystem.load(conf);

  _inputSubsystem.onQuit().connect([&]() { _quit.fire(); });
  _inputSubsystem.onCancel().connect([&]() { _previous.fire(); });
  _inputSubsystem.onLeft().connect([&]() { _gameplaySubsystem.previous(); });
  _inputSubsystem.onRight().connect([&]() { _gameplaySubsystem.next(); });
  _inputSubsystem.onAccept().connect([&]() { _gameplaySubsystem.select(); });

  _gameplaySubsystem.onSelect().connect([&](EntityID entityID) { _graphicsSubsystem.setStyle(entityID, selectedStyle); });
  _gameplaySubsystem.onDeselect().connect([&](EntityID entityID) { _graphicsSubsystem.setStyle(entityID, normalStyle); });
  _gameplaySubsystem.onShow().connect([&](EntityID entityID) { _graphicsSubsystem.setVisibility(entityID, true); });
  _gameplaySubsystem.onHide().connect([&](EntityID entityID) { _graphicsSubsystem.setVisibility(entityID, false); });
  _gameplaySubsystem.onScore().connect([&]() { _hudSubsystem.increaseScore(); });
  _gameplaySubsystem.onMiss().connect([&]() { _hudSubsystem.increaseMisses(); });

  _gameplaySubsystem.onSelect().connect([&](EntityID entityID) { _soundSubsystem->play(entityID); });

  _gameplaySubsystem.startGame();
}

void MainLoop::run()
{
  _inputSubsystem.run();

  _window->clear();

  _graphicsSubsystem.run();
  _hudSubsystem.run();

  _window->display();
}

Signal<>& MainLoop::onPrevious()
{
  return _previous;
}

Signal<>& MainLoop::onQuit()
{
  return _quit;
}
