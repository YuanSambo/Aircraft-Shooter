///////////////////////////////////////////////////////////////
//  Game.cpp
//  Aircraft-Shooter
//
//  Created by Yuan Sambo on 23/12/2020
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#include "../include/Game.hpp"


const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
Game* Game:: m_instance = nullptr;

Game::Game()
: m_window(sf::VideoMode(640, 480), "Aircraft Shooter",sf::Style::Close)
    , m_isMovingLeft(false)
    , m_isMovingRight(false)
    , m_isMovingUp(false)
    , m_isMovingDown(false)
    , m_isPaused(false)
    , m_world(m_window)
    , m_player()
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

    if(Game::m_instance == nullptr)
        m_instance = new Game();

    return m_instance;
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

            if(!m_isPaused)
                update(TimePerFrame);


        }
        processInput();
        m_fpsCounter.updateFrame(deltaTime);
        render();
    }
}


void Game::processInput() {

    CommandQueue&   commands = m_world.getCommandQueue();

    sf::Event event{};
    while (m_window.pollEvent(event)) {

        m_player.handleEvent(event,commands);
        handleWindowEvent(event);
    }

    m_player.handleRealTimeInput(commands);
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

Game::~Game() {

    delete m_instance;
}

void Game::handleWindowEvent(sf::Event event) {

    switch(event.type){
        case sf::Event::GainedFocus:
            m_isPaused = false;
            break;
        case sf::Event::LostFocus:
            m_isPaused=true;
            break;
        case sf::Event::Closed:
            m_window.close();
            break;
    }
}





