#include "../include/Game.hpp"

Game::Game()
    : window(sf::VideoMode({WIDTH, HEIGHT}), NAME),
      position({POSITION_X, POSITION_Y}), velocity({0.0f, 0.0f}) {
  bird.setSize({SIZE_X, SIZE_Y});
  bird.setPosition({position[0], position[1]});
  bird.setFillColor(COLOR);
}

void Game::run() {
  while (window.isOpen()) {
    float dt = clock.restart().asSeconds();
    // Event
    while (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
      // Input
      if (event->is<sf::Event::KeyPressed>()) {
        auto keyEvent = event->getIf<sf::Event::KeyPressed>();
        if (keyEvent && keyEvent->code == sf::Keyboard::Key::Space) {
          velocity[1] = JUMP;
        }
      }
    }

    // update
    velocity[1] += GRAVITY * dt;

    position[0] += velocity[0] * dt;
    position[1] += velocity[1] * dt;

    bird.setPosition({position[0], position[1]});

    if (position[1] > HEIGHT - 40) {
      position[1] = HEIGHT - 40;
      velocity = {0.0f, 0.0f};
    } else if (position[1] < 0) {
      position[1] = 0.0f;
      velocity = {0.0f, 0.0f};
    }

    // Draw
    window.clear();
    window.draw(bird);
    window.display();
  }
}
