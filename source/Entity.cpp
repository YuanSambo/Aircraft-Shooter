///////////////////////////////////////////////////////////////
//  Entity.cpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 28/12/2020                         
//  Copyright (c) 2020 Yuan Sambo All rights reserved.     
////////////////////////////////////////////////////////////////

#include "../include/Entity.hpp"

void Entity::setVelocity(sf::Vector2f velocity) {
    m_velocity = velocity;
}

void Entity::setVelocity(float vx, float vy) {
    m_velocity.x = vx;
    m_velocity .y = vy;
}

sf::Vector2f Entity::getVelocity() const {
    return m_velocity;
}

void Entity::updateCurrent(sf::Time deltaTime) {

    move(m_velocity*deltaTime.asSeconds());
}
