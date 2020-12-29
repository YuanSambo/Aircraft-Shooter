///////////////////////////////////////////////////////////////
//  Aircraft.cpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 29/12/2020                         
//  Copyright (c) 2020 Yuan Sambo All rights reserved.     
////////////////////////////////////////////////////////////////

#include "../include/Aircraft.hpp"
#include "../include/ResourceManager.hpp"

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

    m_sprite.setOrigin(bounds.width/2.f,bounds.height/2.f);

}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {

    target.draw(m_sprite,states);

}
