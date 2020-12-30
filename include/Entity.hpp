///////////////////////////////////////////////////////////////
//  Entity.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 28/12/2020
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_ENTITY_HPP
#define AIRCRAFT_SHOOTER_ENTITY_HPP
#include "SFML/Graphics.hpp"
#include "SceneNode.hpp"

//////////////////////////////////////////////
/// \brief  Denotes a game element in the world
///
//////////////////////////////////////////////
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

     void               updateCurrent(sf:: Time deltaTime) override;


private:
    sf::Vector2f        m_velocity;
};


#endif //AIRCRAFT_SHOOTER_ENTITY_HPP
