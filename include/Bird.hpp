#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

#define WIDTH 800
#define HEIGHT 600

#define SIZE_X 40
#define SIZE_Y 40

#define POSITION_X 20.0f
#define POSITION_Y HEIGHT / 2.0f

#define COLOR sf::Color::Green

#define JUMP -300.0f
#define GRAVITY 9.81f * 150.0f

class Bird {
public:
  Bird();

  void update(float dt);
  void jump();
  void draw(sf::RenderWindow &window);

private:
  sf::RectangleShape shape;
  float velocityY;
  sf::Vector2f position;
};
