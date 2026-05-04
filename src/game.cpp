#include "../include/Game.hpp"

Game::Game()
    : window(sf::VideoMode({WIDTH, HEIGHT}), NAME),
      position({100.0f, HEIGHT / 2.0f}), velocity({0.0f, 0.0f}) {
  bird.setSize({40, 40});
  bird.setPosition({position[0], position[1]});
  bird.setFillColor(sf::Color::Yellow);
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
          velocity[1] = -300.0f;
        }
      }
    }

    // update
    float gravity = 981.0f;
    velocity[1] += gravity * dt;

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
