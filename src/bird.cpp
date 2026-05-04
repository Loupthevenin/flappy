#include "../include/Bird.hpp"

Bird::Bird() : velocityY(0), position(POSITION_X, POSITION_Y) {
  shape.setSize({SIZE_X, SIZE_Y});
  shape.setPosition(position);
  shape.setFillColor(COLOR);
}

void Bird::update(float dt) {
  velocityY += GRAVITY * dt;
  position.y += velocityY * dt;

  if (position.y > HEIGHT - SIZE_Y) {
    position.y = HEIGHT - SIZE_Y;
    velocityY = 0.0f;
  } else if (position.y < 0) {
    position.y = 0.0f;
    velocityY = 0.0f;
  }

  shape.setPosition(position);
}

void Bird::jump() { velocityY = JUMP; }

void Bird::draw(sf::RenderWindow &window) { window.draw(shape); }

sf::FloatRect Bird::getBounds() const { return shape.getGlobalBounds(); }

float Bird::getX() const { return position.x; }
