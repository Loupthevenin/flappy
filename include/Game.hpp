#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

#define WIDTH 800
#define HEIGHT 600
#define NAME "Flappy"

class Game {
public:
  Game();
  void run();

private:
  sf::RenderWindow window;
  sf::RectangleShape bird;
  std::vector<float> position;
  std::vector<float> velocity;
  sf::Clock clock;
};
