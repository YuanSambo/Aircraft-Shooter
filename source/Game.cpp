///////////////////////////////////////////////////////////////
//  Game.cpp
//  Aircraft-Shooter
//
//  Created by Yuan Sambo on 23/12/2020
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#include "../include/Game.hpp"


const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
Game* Game:: Instance = nullptr;

Game::Game()
: m_window(sf::VideoMode(640, 480), "Aircraft Shooter",sf::Style::Close)
    , m_IsMovingLeft(false)
    , m_IsMovingRight(false)
    , m_IsMovingUp(false)
    , m_IsMovingDown(false)
    ,m_world(m_window)
    {
    m_fontManager.load(Fonts::Sansation,"res/Fonts/Sansation.ttf");

        // Frame Limit
        m_window.setFramerateLimit(60);


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


    sf:: Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (m_window.isOpen()) {

        // Fixed Time Steps
        sf:: Time deltaTime = clock.restart();
        timeSinceLastUpdate += deltaTime;

        while(timeSinceLastUpdate>TimePerFrame){

            timeSinceLastUpdate -= TimePerFrame;

            processEvents();
            update(TimePerFrame);
        }

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

    m_world.update(deltaTime);
}

void Game::render() {

    m_window.clear();
    m_world.draw();

    m_window.setView(m_window.getDefaultView());
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




