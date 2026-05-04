#pragma once

#include "settings.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

class Bird {
public:
  Bird();

  void update(float dt);
  void jump();
  void draw(sf::RenderWindow &window);

  sf::FloatRect getBounds() const;

private:
  sf::RectangleShape shape;
  float velocityY;
  sf::Vector2f position;
};
