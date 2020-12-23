//
//  Game.cpp
//  SFML-ShootEmUp
//
//  Created by Yuan Sambo on 23/12/2020.
//  Copyright © 2020 Yuan Sambo. All rights reserved.
//
#include "Game.hpp"

Game::Game() : m_window(sf::VideoMode(640, 480), "SFML Application"), m_player() {

    // Load textures

    //TODO: Unable to open file in exe.
   if(!m_texture.loadFromFile("./res/Textures/Eagle.png")){
       printf("Error");
   }

   m_player.setTexture(m_texture);
   m_player.setPosition((640.f/2)-m_texture.getSize().x,(480.f/2)-m_texture.getSize().y);
}

void Game::run() {

    sf:: Clock clock;
    while (m_window.isOpen()) {

        //TODO: Fixed Time Step
        sf:: Time deltaTime = clock.restart();
        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::processEvents() {

    sf::Event event{};
    while (m_window.pollEvent(event)) {

        switch(event.type){
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code,true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code,false);
                break;
                case sf::Event::Closed:
                    m_window.close();
                    break;
        }
    }
}

// Updates the game logic
void Game::update(sf::Time deltaTime) {

    // Player movement
    sf::Vector2f movement (0.f,0.f);
    float speed = 100.f;
    if(mIsMovingUp)
        movement.y -= 1.f;
    if(mIsMovingDown)
        movement.y += 1.f;
    if(mIsMovingRight)
        movement.x += 1.f;
    if(mIsMovingLeft)
        movement.x -= 1.f;

    m_player.move((movement*speed)*deltaTime.asSeconds());
}


// Renders the game on the screen
void Game::render() {
    m_window.clear();
    m_window.draw(m_player);
    m_window.display();
}


// Handles player input and controls.
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {

    // Player controls
    if(key == sf::Keyboard::W)
        mIsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        mIsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        mIsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        mIsMovingRight = isPressed;
}
