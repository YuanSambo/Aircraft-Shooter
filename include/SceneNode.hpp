///////////////////////////////////////////////////////////////
//  SceneNode.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 28/12/2020                         
//  Copyright (c) 2020 Yuan Sambo. All rights reserved.     
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_SCENENODE_HPP
#define AIRCRAFT_SHOOTER_SCENENODE_HPP

#include "SFML/Graphics.hpp"
#include <memory>
#include <vector>

class SceneNode : public sf::Transformable, public sf:: Drawable,
private sf::NonCopyable{

public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    SceneNode();

    //////////////////////////////////////
    /// \brief Attach node as a child
    //  \param Child to be attached
    //////////////////////////////////////
    void            attachChild(Ptr child);

    //////////////////////////////////////
    /// \brief Detach child from the node
    //  \param Child node to be detached
    //////////////////////////////////////
    Ptr             detachChild(const SceneNode& node);

private:

    virtual void        draw(sf::RenderTarget& target, sf::RenderStates states) const;
    virtual void        drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
    void                drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
    std::vector<Ptr> m_children;
    SceneNode*       m_parent;

private:

};


#endif //AIRCRAFT_SHOOTER_SCENENODE_HPP
