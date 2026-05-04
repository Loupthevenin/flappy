#pragma once

#include "settings.hpp"
#include <SFML/Graphics.hpp>

class Pipe {
public:
  Pipe(float x, float gapY);

  void update(float dt, float speed);
  void draw(sf::RenderWindow &window);

  bool isOffScreen() const;

  sf::FloatRect getTopBounds() const;
  sf::FloatRect getBotBounds() const;

  bool scored;

  float getX() const;

private:
  sf::RectangleShape topPipe;
  sf::RectangleShape botPipe;

  float x;
  float speed;
  float gapSize;
};
