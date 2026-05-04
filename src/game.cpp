#include "../include/Game.hpp"

Game::Game() : window(sf::VideoMode({WIDTH, HEIGHT}), NAME), bird() {}

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
          bird.jump();
        }
      }
    }

    // update
    bird.update(dt);

    // Draw
    window.clear();
    bird.draw(window);
    window.display();
  }
}
