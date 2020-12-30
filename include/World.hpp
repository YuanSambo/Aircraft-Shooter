///////////////////////////////////////////////////////////////
//  World.hpp
//  Aircraft-Shooter
//
//  Created by Yuan Sambo on 30/12/2020
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_WORLD_HPP
#define AIRCRAFT_SHOOTER_WORLD_HPP

#include "SFML/Graphics.hpp"
#include "SceneNode.hpp"
#include "ResourceManager.hpp"
#include "ResourceIdentifiers.hpp"
#include "array"
#include "Aircraft.hpp"

class World : private sf::NonCopyable {

public:
    explicit            World(sf::RenderWindow &window);

    void                update(sf::Time deltaTime);

    void                draw();

private:

    //////////////////////////////////////////
    /// \brief Loads world textures
    ///
    /////////////////////////////////////////
    void                loadTextures();

    //////////////////////////////////////////
    /// \brief Builds the scene world
    ///
    /////////////////////////////////////////
    void                buildScene();

private:

    enum Layer {
        Background,
        Air,
        LayerCount
    };

private:

    sf::RenderWindow&           m_window;
    sf::View                    m_worldView;
    SceneNode                   m_sceneGraph;
    std::array<SceneNode *,
            LayerCount>                 m_sceneLayers;


    TextureManager              m_textureManager;
    sf::FloatRect               m_worldBounds;
    sf::Vector2f                m_spawnPosition;

    float                       m_scrollSpeed;
    Aircraft*                   m_playerAircraft;


};


#endif //AIRCRAFT_SHOOTER_WORLD_HPP
