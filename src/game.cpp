#include "../include/Game.hpp"

Game::Game() : window(sf::VideoMode({WIDTH, HEIGHT}), NAME) {}

void Game::run() {
  while (window.isOpen()) {
    while (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }
    window.clear();
    window.display();
  }
}
