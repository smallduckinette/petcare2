#include <SFML/Graphics.hpp>

class HudSubsystem
{
public:
  HudSubsystem(sf::RenderWindow* window);

  void increaseScore();
  void increaseMisses();

  void run();

private:
  void update();

  sf::RenderWindow* _window;

  sf::Font _font;
  sf::Text _text;

  int _score;
  int _misses;
};
