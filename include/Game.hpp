///////////////////////////////////////////////////////////////
//  Game.hpp
//  Aircraft-Shooter
//
//  Created by Yuan Sambo on 23/12/2020
//  Copyright (c) 2020 Yuan Sambo All rights reserved.
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_GAME_HPP
#define AIRCRAFT_SHOOTER_GAME_HPP


#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "FPSCounter.hpp"
#include "ResourceIdentifiers.hpp"
#include "World.hpp"

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

    static Game*                Instance;
    static const sf::Time       TimePerFrame;

    FontManager                m_fontManager;

    sf::RenderWindow    m_window;
    sf::Text            m_fps;

    yu::FPSCounter      m_fpsCounter;
    World               m_world;


    bool    m_IsMovingUp;
    bool    m_IsMovingDown;
    bool    m_IsMovingRight;
    bool    m_IsMovingLeft;


private:


    //////////////////////////////////////////
    /// \brief Handles event inside the game.
    ///
    /////////////////////////////////////////
    void        processEvents();

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
    /// \brief Handles player keyboard input
    ///
    /// \param KeyboardKey
    /// \param isPressed
    ///
    /////////////////////////////////////////
    void        handlePlayerInput(sf::Keyboard::Key key, bool isPressed);



};

#endif  //AIRCRAFT_SHOOTER_GAME_HPP
