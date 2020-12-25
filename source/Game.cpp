///////////////////////////////////////////////////////////////
//  Game.cpp
//  Aircraft-Shooter
//
//  Created by Yuan Sambo on 23/12/2020
//  Copyright (c) 2020 Yuan Sambo All rights reserved.
////////////////////////////////////////////////////////////////

#include "Game.hpp"


const float Game::PlayerSpeed =100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
Game* Game:: Instance = nullptr;

Game::Game()
: m_window(sf::VideoMode(640, 480), "Aircraft Shooter",sf::Style::Close)
    , m_texture()
    , m_player()
    , m_font()
    , m_textureManager()
    , m_fontManager()
    , m_fpsText()
    , m_fpsCounter()
    , mIsMovingLeft(false)
    , mIsMovingRight(false)
    , mIsMovingUp(false)
    , mIsMovingDown(false)

    {

    try{

        m_textureManager.load(Textures::Airplane, "res/Textures/Eagle.png");
        m_fontManager.load(Fonts::Sansation,"res/Fonts/Sansation.ttf");

    } catch (std::runtime_error& e) {

        printf("Exception %s \n",e.what());

    }

   m_window.setFramerateLimit(60);

   m_player.setTexture(m_textureManager.get(Textures::Airplane));
   m_player.setPosition(270.f,200.f);

   m_fpsText.setFont(m_fontManager.get(Fonts::Sansation));
   m_fpsText.setPosition(5.f, 5.f);
   m_fpsText.setCharacterSize(10);

   m_fpsCounter.setText(m_fpsText);

    }

Game* Game::instance() {

    if(Game::Instance == nullptr)
        Instance = new Game();

    return Instance;
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
        m_fpsCounter.updateFrame(deltaTime);
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
void Game::render() {

    m_window.clear();
    m_window.draw(m_player);
    m_window.draw(m_fpsText);
    m_window.display();
}
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




