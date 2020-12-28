///////////////////////////////////////////////////////////////
//  Game.cpp
//  Aircraft-Shooter
//
//  Created by Yuan Sambo on 23/12/2020
//  Copyright (c) 2020 Yuan Sambo All rights reserved.
////////////////////////////////////////////////////////////////

#include "../include/Game.hpp"


const float Game::PlayerSpeed =100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
Game* Game:: Instance = nullptr;

Game::Game()
: m_window(sf::VideoMode(640, 480), "Aircraft Shooter",sf::Style::Close)
    , m_IsMovingLeft(false)
    , m_IsMovingRight(false)
    , m_IsMovingUp(false)
    , m_IsMovingDown(false)
    {}


void Game::init() {

    try{
        m_textureManager.load(Textures::Eagle, "res/Textures/Eagle.png");
        m_textureManager.load(Textures::Desert,"res/Textures/Desert.png");
        m_fontManager.load(Fonts::Sansation,"res/Fonts/Sansation.ttf");

    } catch (std::runtime_error& e) {

        printf("Exception %s \n",e.what());

    }

    // Frame Limit
    m_window.setFramerateLimit(60);

    m_player.setTexture(m_textureManager.get(Textures::Eagle));
    m_player.setPosition(270.f,200.f);

    m_landScape.setTexture(m_textureManager.get(Textures::Desert));

    m_fps.setFont(m_fontManager.get(Fonts::Sansation));
    m_fps.setPosition(5.f, 5.f);
    m_fps.setCharacterSize(10);

    m_fpsCounter.setText(m_fps);

}


Game* Game::instance() {

    if(Game::Instance == nullptr)
        Instance = new Game();

    return Instance;
}

void Game::run() {

    this->init();

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

    if(m_IsMovingUp)
        movement.y -= PlayerSpeed;
    if(m_IsMovingDown)
        movement.y += PlayerSpeed;
    if(m_IsMovingRight)
        movement.x += PlayerSpeed;
    if(m_IsMovingLeft)
        movement.x -= PlayerSpeed;

    // Applies movement to the player
    m_player.move(movement*deltaTime.asSeconds());
}
void Game::render() {

    m_window.clear();
    m_window.draw(m_landScape);
    m_window.draw(m_player);
    m_window.draw(m_fps);
    m_window.display();
}
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {

    // Player controls
    if(key == sf::Keyboard::W)
        m_IsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        m_IsMovingDown = isPressed;
    else if (key == sf::Keyboard::A)
        m_IsMovingLeft = isPressed;
    else if (key == sf::Keyboard::D)
        m_IsMovingRight = isPressed;
}

Game::~Game() {
    delete Instance;
}




