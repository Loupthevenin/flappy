#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

#define WIDTH 800
#define HEIGHT 600
#define NAME "Flappy"

#define SIZE_X 40
#define SIZE_Y 40

#define POSITION_X 20.0f
#define POSITION_Y HEIGHT / 2.0f

#define COLOR sf::Color::Green

#define JUMP -300.0f
#define GRAVITY 9.81f * 150.0f

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
