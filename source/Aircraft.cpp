///////////////////////////////////////////////////////////////
//  Aircraft.cpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 29/12/2020
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#include "../include/Aircraft.hpp"
#include "../include/ResourceManager.hpp"
#include "../include/Category.hpp"

Textures toTextureID(Aircraft::Type type){

    switch(type){

        case Aircraft::Type::Eagle:
            return Textures::Eagle;

        case Aircraft::Type::Raptor:
            return Textures::Raptor;
    }

    return Textures::Eagle;
}
Aircraft::Aircraft(Aircraft::Type type, const TextureManager &textures):
        m_type(type),
        m_sprite(textures.get(toTextureID(type))){


    // Sprite's local bounds
    sf::FloatRect bounds = m_sprite.getLocalBounds();

    // Centers the sprite
    m_sprite.setOrigin(bounds.width/2.f,bounds.height/2.f);

}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {

    target.draw(m_sprite,states);

}

unsigned int Aircraft::getCategory() const {

    switch (m_type) {

        case Eagle:
            return Category::PlayerAircraft;
        default:
            return Category::EnemyAircraft;

    }

}

void Aircraft::accelerate(float vx, float vy) {
    setVelocity(getVelocity().x + vx, getVelocity().y+vy);
}

void Aircraft::accelerate(sf::Vector2f velocity) {
    setVelocity(getVelocity() +velocity );

}
