#include "Game_GUI.hpp"

GameGUI::GameGUI() : window(sf::VideoMode(800, 600), "Monopoly Game") {
    // Initialize game objects and resources here
}

void GameGUI::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void GameGUI::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void GameGUI::update() {
    // Update game logic here
}

void GameGUI::render() {
    window.clear();
    // Draw your game objects here
    window.display();
}