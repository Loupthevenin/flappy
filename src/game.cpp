#include "../include/Game.hpp"
#include <string>

Game::Game()
    : window(sf::VideoMode({WIDTH, HEIGHT}), NAME), bird(), score(0), font(),
      scoreText(font), pipeSpeed(200.0f) {

  font.openFromFile("../assets/arial.ttf");

  scoreText.setFont(font);
  scoreText.setCharacterSize(40);
  scoreText.setFillColor(COLOR_TEXT);
  scoreText.setPosition({20, 20});
}

void Game::handleEvents() {
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
}

void Game::update(float dt) {
  spawnPipes();
  updateBird(dt);
  updatePipes(dt);
  checkCollisions();
  updateScore();
  if (score > 10) {
    pipeSpeed = SPEED_PIPE + score * 10.0f;
  }
}

void Game::updateBird(float dt) { bird.update(dt); }

void Game::spawnPipes() {
  if (pipeClock.getElapsedTime().asSeconds() > 2.f) {
    float gapY = 150.f + std::rand() % 250;
    pipes.emplace_back(800.f, gapY);
    pipeClock.restart();
  }
}

void Game::updatePipes(float dt) {
  for (auto &pipe : pipes) {
    pipe.update(dt, pipeSpeed);

    if (!pipe.scored && pipe.getX() + SIZE_PIPE < bird.getX()) {
      score++;
      pipe.scored = true;
    }
  }
}

void Game::checkCollisions() {
  for (auto &pipe : pipes) {
    if (bird.getBounds().findIntersection(pipe.getTopBounds()) ||
        bird.getBounds().findIntersection(pipe.getBotBounds())) {
      window.close(); // game over simple pour l’instant
    }
  }
}

void Game::updateScore() { scoreText.setString(std::to_string(score)); }

void Game::render() {
  window.clear();

  bird.draw(window);

  for (auto &pipe : pipes) {
    pipe.draw(window);
  }

  window.draw(scoreText);
  window.display();
}

void Game::run() {
  while (window.isOpen()) {
    float dt = clock.restart().asSeconds();

    handleEvents();
    update(dt);
    render();
  }
}
