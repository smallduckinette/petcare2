#include "TitleScene.h"


TitleScene::TitleScene(const config::Config& conf,
                       sf::RenderWindow* window,
                       TextureCache* textureCache):
  _window(window),
  _inputSubsystem(window),
  _titleSubsystem(window, textureCache)
{
  _titleSubsystem.load(conf);

  _inputSubsystem.onQuit().connect([&]() { _quit.fire(); });
  _inputSubsystem.onCancel().connect([&]() { _quit.fire(); });
  _inputSubsystem.onAccept().connect([&]() { _start.fire(); });
}

void TitleScene::run()
{
  _inputSubsystem.run();

  _window->clear();

  _titleSubsystem.run();

  _window->display();
}

Signal<>& TitleScene::onStart()
{
  return _start;
}

Signal<>& TitleScene::onQuit()
{
  return _quit;
}
