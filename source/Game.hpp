//
//  Game.cpp
//  SFML-ShootEmUp
//
//  Created by Yuan Sambo on 23/12/2020.
//  Copyright © 2020 Yuan Sambo. All rights reserved.
//
#include <SFML/Graphics.hpp>


class Game {
public:
    Game();

    void run();

private:
    void processEvents();
    void update(sf::Time deltaTime);
    void render();

private:
    sf::Texture m_texture;
    sf::Sprite m_player;

    sf::RenderWindow m_window;
    bool mIsMovingUp = false;
    bool mIsMovingDown = false;
    bool mIsMovingRight = false;
    bool mIsMovingLeft = false;


    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


};