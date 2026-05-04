#include "../include/Game.hpp"
#include <string>

Game::Game()
    : window(sf::VideoMode({WIDTH, HEIGHT}), NAME), bird(), score(0), font(),
      scoreText(font) {

  font.openFromFile("../assets/arial.ttf");

  scoreText.setFont(font);
  scoreText.setCharacterSize(40);
  scoreText.setFillColor(COLOR_TEXT);
  scoreText.setPosition({20, 20});
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
          bird.jump();
        }
      }
    }

    // Spawn pipe / 2s
    if (pipeClock.getElapsedTime().asSeconds() > 2.f) {
      float gapY = 150.f + std::rand() % 250;
      pipes.emplace_back(800.f, gapY);
      pipeClock.restart();
    }

    // update
    bird.update(dt);
    for (auto &pipe : pipes) {
      pipe.update(dt);
      if (!pipe.scored && pipe.getX() + SIZE_PIPE < bird.getX()) {
        score++;
        pipe.scored = true;
      }
      for (auto &pipe : pipes) {
        if (bird.getBounds().findIntersection(pipe.getTopBounds()) ||
            bird.getBounds().findIntersection(pipe.getBotBounds())) {
          window.close(); // game over simple pour l’instant
        }
      }
    }

    scoreText.setString(std::to_string(score));

    // Draw
    window.clear();
    bird.draw(window);
    for (auto &pipe : pipes) {
      pipe.draw(window);
    }
    window.draw(scoreText);
    window.display();
  }
}
