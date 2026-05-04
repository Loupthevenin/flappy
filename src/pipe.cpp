#include "../include/Pipe.hpp"

Pipe::Pipe(float startX, float gapY)
    : x(startX), speed(SPEED_PIPE), gapSize(GAPSIZE), scored(false) {
  topPipe.setSize({SIZE_PIPE, gapY});
  topPipe.setPosition({x, 0.0f});
  topPipe.setFillColor(COLOR_PIPE);

  botPipe.setSize({SIZE_PIPE, HEIGHT - (gapY + gapSize)});
  botPipe.setPosition({x, gapY + gapSize});
  botPipe.setFillColor(COLOR_PIPE);
}

void Pipe::update(float dt, float speed) {
  x -= speed * dt;
  topPipe.setPosition({x, 0});
  botPipe.setPosition({x, botPipe.getPosition().y});
}

void Pipe::draw(sf::RenderWindow &window) {
  window.draw(topPipe);
  window.draw(botPipe);
}

bool Pipe::isOffScreen() const { return x < -SIZE_PIPE; }

sf::FloatRect Pipe::getTopBounds() const { return topPipe.getGlobalBounds(); }

sf::FloatRect Pipe::getBotBounds() const { return botPipe.getGlobalBounds(); }

float Pipe::getX() const { return x; }
