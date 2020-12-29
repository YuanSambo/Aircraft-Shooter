///////////////////////////////////////////////////////////////
//  Aircraft.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 29/12/2020                         
//  Copyright (c) 2020 Yuan Sambo. All rights reserved.     
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_AIRCRAFT_HPP
#define AIRCRAFT_SHOOTER_AIRCRAFT_HPP


#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"

class Aircraft : public Entity {

public:
     enum class Type{
        Eagle,
        Raptor,
    };
public:
                Aircraft(Type type, const TextureManager& textures);
private:
    void        drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
    Type            m_type;
    sf::Sprite      m_sprite;
};


#endif //AIRCRAFT_SHOOTER_AIRCRAFT_HPP
