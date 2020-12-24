//  Game.hpp
//  Aircraft-Shooter
//
//  Created by Yuan Sambo on 23/12/2020.
//  Copyright © 2020 Yuan Sambo. All rights reserved.
//


#include <SFML/Graphics.hpp>


class Game {
public:

    static  Game* instance();
    void            run();

private:
                        Game();
    static Game*        m_instance;
    static const float PlayerSpeed;
    static const sf::Time TimePerFrame;


    sf::RenderWindow    m_window;
    sf::Texture         m_texture;
    sf::Sprite          m_player;
    sf::Font            m_font;
    sf::Text            m_statisticsText;
    sf::Time            m_statisticsUpdateTime;

    std::size_t         m_statisticsNumFrames;
    bool    mIsMovingUp;
    bool    mIsMovingDown;
    bool    mIsMovingRight;
    bool    mIsMovingLeft;


private:

    void        processEvents();
    void        update(sf::Time deltaTime);
    void        render();
    void        handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
    void        updateStatistics(sf::Time deltaTime);

};