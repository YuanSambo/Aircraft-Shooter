///////////////////////////////////////////////////////////////
//  Entity.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 28/12/2020                         
//  Copyright (c) 2020 Yuan Sambo. All rights reserved.     
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_ENTITY_HPP
#define AIRCRAFT_SHOOTER_ENTITY_HPP
#include "SFML/Graphics.hpp"
#include "SceneNode.hpp"

class Entity : public SceneNode{
public:
    //////////////////////////////////////
    /// \brief Sets the Entity's velocity
    ///
    ///  \param Vector2f velocity
    ///
    //////////////////////////////////////
    void                setVelocity(sf::Vector2f velocity);

    //////////////////////////////////////
    /// \brief Sets the Entity's velocity
    ///
    /// \param float velocity x
    /// \param float velocity y
    ///
    //////////////////////////////////////
    void                setVelocity(float vx, float vy);

    //////////////////////////////////////
    /// \brief Gets the Entity's velocity
    ///
    /// \return Vector2f velocity
    ///
    //////////////////////////////////////
    sf::Vector2f        getVelocity() const;

private:
    sf::Vector2f        m_velocity;

};


#endif //AIRCRAFT_SHOOTER_ENTITY_HPP
