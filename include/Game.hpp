#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

#define WIDTH 800
#define HEIGHT 600
#define NAME "Flappy"

class Game {
public:
  Game();
  void run();

private:
  sf::RenderWindow window;
};
