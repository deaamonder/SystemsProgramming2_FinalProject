#ifndef GAME_GUI_HPP
#define GAME_GUI_HPP

#include <SFML/Graphics.hpp>

using namespace std;

class GameGUI {
public:
    GameGUI();
    void run();

private:
    void processEvents();
    void update();
    void render();

    sf::RenderWindow window;
    // Add other necessary variables (like your game objects)
};

#endif // GAME_GUI_HPP