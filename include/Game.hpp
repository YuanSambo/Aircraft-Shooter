///////////////////////////////////////////////////////////////
//  Game.hpp
//  Aircraft-Shooter
//
//  Created by Yuan Sambo on 23/12/2020
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_GAME_HPP
#define AIRCRAFT_SHOOTER_GAME_HPP


#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "FPSCounter.hpp"
#include "ResourceIdentifiers.hpp"
#include "World.hpp"
#include "Player.hpp"

//////////////////////////////////////////
/// \brief Game engine
///
/////////////////////////////////////////
class Game : private sf::NonCopyable {

public:

    //////////////////////////////////////////
    /// \brief Constructor
    ///
    /////////////////////////////////////////
    Game();

    //////////////////////////////////////////
    /// \brief Destructor
    ///
    /////////////////////////////////////////
    ~Game();

    //////////////////////////////////////////
    /// \brief  Gets the instance of the game
    /// \return The instance of the game
    ///
    /////////////////////////////////////////
    static  Game* instance();

    //////////////////////////////////////////
    /// \brief Starts the game loop.
    ///
    /////////////////////////////////////////
    void            run();



private:

    static Game*                m_instance;
    static const sf::Time       TimePerFrame;

    FontManager                m_fontManager;

    sf::RenderWindow    m_window;
    sf::Text            m_fps;

    yu::FPSCounter      m_fpsCounter;
    World               m_world;
    Player              m_player;


    bool    m_isMovingUp;
    bool    m_isMovingDown;
    bool    m_isMovingRight;
    bool    m_isMovingLeft;
    bool    m_isPaused;


private:


    //////////////////////////////////////////
    /// \brief Handles input inside the game.
    ///
    /////////////////////////////////////////
    void        processInput();

    //////////////////////////////////////////
    /// \brief Updates the game logic.
    ///
    /// \param deltaTime
    ///
    /////////////////////////////////////////
    void        update(sf::Time deltaTime);

    //////////////////////////////////////////
    /// \brief Renders graphics on the window.
    ///
    /////////////////////////////////////////
    void        render();

    //////////////////////////////////////////
    /// \brief Handles windows event
    ///
    /////////////////////////////////////////
    void        handleWindowEvent(sf::Event event);

};

#endif  //AIRCRAFT_SHOOTER_GAME_HPP
