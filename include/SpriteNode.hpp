///////////////////////////////////////////////////////////////
//  SpriteNode.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 30/12/2020
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_SPRITENODE_HPP
#define AIRCRAFT_SHOOTER_SPRITENODE_HPP

#include "SFML/Graphics.hpp"
#include "SceneNode.hpp"

/////////////////////////////////////////////////
/// \brief Simple sprite node that can be plugged
/// into the tree structure.
///////////////////////////////////////////////
class SpriteNode : public SceneNode {

public:
    explicit            SpriteNode(const sf::Texture& texture);
                        SpriteNode(const sf::Texture& texture,
                                   const sf::IntRect& rect);
private:
     void        drawCurrent(sf::RenderTarget& target,
                                    sf::RenderStates states) const override;

private:
    sf::Sprite m_sprite;

};


#endif //AIRCRAFT_SHOOTER_SPRITENODE_HPP
