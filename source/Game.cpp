//  Game.cpp
//  Aircraft-Shooter
//
//  Created by Yuan Sambo on 23/12/2020.
//  Copyright © 2020 Yuan Sambo. All rights reserved.
//
#include <iostream>
#include "Game.hpp"

const float Game::PlayerSpeed =100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
:   m_window(sf::VideoMode(640, 480), "SFML Application")
    ,m_texture()
    ,m_player()
    ,m_font()
    ,m_statisticsText()
    ,m_statisticsNumFrames(0)
    ,m_statisticsUpdateTime()
    ,mIsMovingLeft(false)
    ,mIsMovingRight(false)
    ,mIsMovingUp(false)
    ,mIsMovingDown(false)
    {

    // Handles loading file errors.
   if(!m_texture.loadFromFile("res/Textures/Eagle.png"))
       printf("Error loading player sprite.");
   if(!m_font.loadFromFile("res/Fonts/Sansation.ttf"))
       printf("Error loading font.");

   m_window.setFramerateLimit(60);

   m_player.setTexture(m_texture);
   m_player.setPosition((640.f/2)-m_texture.getSize().x,(480.f/2)-m_texture.getSize().y);

   m_statisticsText.setFont(m_font);
   m_statisticsText.setPosition(5.f,5.f);
   m_statisticsText.setCharacterSize(10);
}

void Game::run() {

    sf:: Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (m_window.isOpen()) {

        // Fixed Time Steps
        sf:: Time deltaTime = clock.restart();
        timeSinceLastUpdate += deltaTime;

        while(timeSinceLastUpdate>TimePerFrame){

            timeSinceLastUpdate -= TimePerFrame;

            update(TimePerFrame);
        }

        processEvents();
        updateStatistics(deltaTime);
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

    if(mIsMovingUp)
        movement.y -= PlayerSpeed;
    if(mIsMovingDown)
        movement.y += PlayerSpeed;
    if(mIsMovingRight)
        movement.x += PlayerSpeed;
    if(mIsMovingLeft)
        movement.x -= PlayerSpeed;

    // Applies movement to the player
    m_player.move(movement*deltaTime.asSeconds());
}


// Renders the game on the screen
void Game::render() {

    m_window.clear();
    m_window.draw(m_player);
    m_window.draw(m_statisticsText);
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

// Computes  Frames Per Second
void Game::updateStatistics(sf::Time deltaTime) {

    m_statisticsUpdateTime += deltaTime;
    m_statisticsNumFrames += 1;

    if (m_statisticsUpdateTime >= sf::seconds(1.0f)) {
        m_statisticsText.setString(
                "FPS = " + std::to_string(m_statisticsNumFrames) + "\n" +
                "Time / Update = " + std::to_string(m_statisticsUpdateTime.asMicroseconds() / m_statisticsNumFrames) +
                "us");

        m_statisticsUpdateTime -= sf::seconds(1.0f);
        m_statisticsNumFrames = 0;

    }

}