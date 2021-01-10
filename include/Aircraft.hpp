///////////////////////////////////////////////////////////////
//  Aircraft.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 29/12/2020
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_AIRCRAFT_HPP
#define AIRCRAFT_SHOOTER_AIRCRAFT_HPP


#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"

class Aircraft : public Entity {

public:
     enum  Type{
        Eagle,
        Raptor,
    };
public:
                        Aircraft(Type type, const TextureManager& textures);
                        void accelerate(float vx , float vy);
                        void accelerate( sf::Vector2f velocity);
private:

    ////////////////////////////
    /// \brief Draw current node
    ///
    /// \param target
    /// \param states
    ///
    ////////////////////////////
     void               drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const override;

    ////////////////////////////
    /// \brief Get node category
    ///
    ////////////////////////////
     unsigned int       getCategory() const override;
private:
    Type            m_type;
    sf::Sprite      m_sprite;
};


#endif //AIRCRAFT_SHOOTER_AIRCRAFT_HPP
