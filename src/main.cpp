#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Flappy");

  while (window.isOpen()) {
    while (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
    }

    window.clear();
    window.display();
  }

  return 0;
}
