#pragma once

#include "Bird.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

#define NAME "Flappy"

class Game {
public:
  Game();
  void run();

private:
  sf::RenderWindow window;
  sf::Clock clock;

  Bird bird;
};
