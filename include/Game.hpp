#pragma once

#include "Bird.hpp"
#include "Pipe.hpp"
#include "settings.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>

class Game {
public:
  Game();

  void handleEvents();
  void update(float dt);
  void updateBird(float dt);
  void spawnPipes();
  void updatePipes(float dt);
  void checkCollisions();
  void updateScore();
  void render();

  void run();

private:
  sf::RenderWindow window;
  sf::Clock clock;

  Bird bird;

  std::vector<Pipe> pipes;
  sf::Clock pipeClock;

  int score;

  sf::Font font;
  sf::Text scoreText;
  float pipeSpeed;
};
