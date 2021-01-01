///////////////////////////////////////////////////////////////
//  World.cpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 30/12/2020
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#include "../include/World.hpp"
#include "../include/SpriteNode.hpp"


World::World(sf::RenderWindow & window)
        : m_window(window)
        , m_worldView(window.getDefaultView())
        , m_textureManager()
        , m_sceneGraph()
        , m_sceneLayers()
        , m_worldBounds(0.f, 0.f, m_worldView.getSize().x, 2000.f)
        , m_spawnPosition(m_worldView.getSize().x / 2.f, m_worldBounds.height - m_worldView.getSize().y / 3.f)
        , m_scrollSpeed(-50.f)
        , m_playerAircraft(nullptr){

        loadTextures();
        buildScene();

        m_worldView.setCenter(m_spawnPosition.x,m_spawnPosition.y-100.f);

}
void World::update(sf::Time deltaTime) {





    // Scrolls the background
    m_worldView.move(0.f, m_scrollSpeed * deltaTime.asSeconds());

    sf::Vector2f position = m_playerAircraft->getPosition();
    sf::Vector2f velocity = m_playerAircraft->getVelocity();

    // Check bounds
    if (position.x <= m_worldBounds.left + 150
        || position.x >= m_worldBounds.left + m_worldBounds.width - 150)
    {
        // Flips velocity
        velocity.x = -velocity.x;
        m_playerAircraft->setVelocity(velocity);
    }

    // Sends command to scene graph
    while(!m_commandQueue.isEmpty())
        m_sceneGraph.onCommand(m_commandQueue.pop(),deltaTime);


    m_sceneGraph.update(deltaTime);
}

void World::draw() {

    m_window.setView(m_worldView);
    m_window.draw(m_sceneGraph);
}

void World::loadTextures() {

    m_textureManager.load(Textures::Eagle, "res/Textures/eagle.png");
    m_textureManager.load(Textures::Raptor, "res/Textures/raptor.png");
    m_textureManager.load(Textures::Desert,"res/Textures/desert.png");
}

void World::buildScene() {

    for (std::size_t i = 0; i < LayerCount; ++i) {

        // Creates layer scene node
        SceneNode::Ptr layer(new SceneNode());

        // Puts the node to the scene layers
        m_sceneLayers[i] = layer.get();

        // Attaches the scene layer to the scene graph
        m_sceneGraph.attachChild(std::move(layer));
    }

        // Sets the background sprite to repeat
        sf::Texture& texture = m_textureManager.get(Textures::Desert);
        sf::IntRect  textureRect(m_worldBounds);
        texture.setRepeated(true);

        // Background Sprite
        std::unique_ptr<SpriteNode> backgroundSprite ( new SpriteNode(texture,textureRect));
        backgroundSprite -> setPosition(m_worldBounds.left,m_worldBounds.top);
        m_sceneLayers[Background] -> attachChild(std::move(backgroundSprite));

        // Aircraft Leader
        std::unique_ptr<Aircraft> leader ( new Aircraft(Aircraft::Type::Eagle,m_textureManager));
        m_playerAircraft = leader.get();
        m_playerAircraft->setPosition(m_spawnPosition);
        m_playerAircraft->setVelocity(40.f,m_scrollSpeed);
        m_sceneLayers[Air] -> attachChild(std::move(leader));

        // Left aircraft
        std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Type::Raptor,m_textureManager));
        leftEscort->setPosition(-80.f, 50.f);
        leftEscort->setScale(0.8f,0.8f);
        m_playerAircraft -> attachChild(std::move(leftEscort));

        // Right aircraft
        std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Type::Raptor,m_textureManager));
        rightEscort->setPosition(80.f, 50.f);
        rightEscort->setScale(0.8f,0.8f);
        m_playerAircraft -> attachChild(std::move(rightEscort));

}

CommandQueue &World::getCommandQueue() {
    return m_commandQueue;
}




