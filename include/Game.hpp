///////////////////////////////////////////////////////////////
//  Game.hpp
//  Aircraft-Shooter
//
//  Created by Yuan Sambo on 23/12/2020
//  Copyright (c) 2020 Yuan Sambo All rights reserved.
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_GAME_HPP
#define AIRCRAFT_SHOOTER_GAME_HPP

namespace Textures{
    enum ID{
        Airplane,
    };
}

namespace Fonts{
    enum ID{
        Sansation,
    };
}
#include <SFML/Graphics.hpp>
#include "ResourceManager.hpp"
#include "FPSCounter.hpp"

//////////////////////////////////////////
/// \brief Game engine
/////////////////////////////////////////
class Game {

public:

    //////////////////////////////////////////
    /// \brief  Gets the instance of the game.
    /// \return The instance of the game.
    /////////////////////////////////////////
    static  Game* instance();

    //////////////////////////////////////////
    /// \brief Starts the game loop.
    /////////////////////////////////////////
    void            run();

private:

    static Game*                Instance;
    static const float          PlayerSpeed;
    static const sf::Time       TimePerFrame;

    ResourceManager<sf::Texture
    ,Textures::ID>              m_textureManager;
    ResourceManager<sf::Font,
    Fonts::ID>                  m_fontManager;

    sf::RenderWindow    m_window;
    sf::Texture         m_texture;
    sf::Sprite          m_player;
    sf::Font            m_font;
    sf::Text            m_fps;

    yu::FPSCounter      m_fpsCounter;


    bool    m_IsMovingUp;
    bool    m_IsMovingDown;
    bool    m_IsMovingRight;
    bool    m_IsMovingLeft;


private:

    //////////////////////////////////////////
    /// \brief Constructor
    /////////////////////////////////////////
                        Game();
    //////////////////////////////////////////
    /// \brief Destructor
    /////////////////////////////////////////
                        ~Game();

    //////////////////////////////////////////
    /// \brief Process the events inside the game.
    /////////////////////////////////////////
    void        processEvents();

    //////////////////////////////////////////
    /// \brief Updates the game logic.
    /// \param Elapsed time since the last frame.
    /////////////////////////////////////////
    void        update(sf::Time deltaTime);

    //////////////////////////////////////////
    /// \brief Renders graphics on the window.
    /////////////////////////////////////////
    void        render();

    //////////////////////////////////////////
    /// \brief Handles player keyboard input
    /// \param Pressed keyboard key.
    /// \param If the key is pressed.
    /////////////////////////////////////////
    void        handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    //////////////////////////////////////////
    /// \brief Initialize objects
    /////////////////////////////////////////
    void        init();



};

#endif  //AIRCRAFT_SHOOTER_GAME_HPP