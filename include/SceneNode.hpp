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

//////////////////////////////////////
/// \brief A scene node that can store an
/// object that is drawn on the screen,
/// most often this is an entity.
///
//////////////////////////////////////
class SceneNode : public sf::Transformable, public sf:: Drawable,
private sf::NonCopyable{

public:
    typedef std::unique_ptr<SceneNode> Ptr;

public:
    SceneNode();

    void            update(sf:: Time deltaTime);
    //////////////////////////////////////
    /// \brief Attach node as a child
    ///
    /// \param Child to be attached
    ///
    //////////////////////////////////////
    void            attachChild(Ptr child);



    ///////////////////////////////
    /// \param node to be detached
    ///
    /// \return Detached child
    ///
    /////////////////////////////
    Ptr             detachChild(const SceneNode& node);

    sf::Transform   getWorldTransform() const;
    sf::Vector2f    getWorldPosition() const;

private:

    void                draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    ////////////////////////////
    /// \brief Draw current node
    ///
    /// \param target
    /// \param states
    ///
    ////////////////////////////
    virtual void        drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    ////////////////////////////
    /// \brief Draw children nodes
    ///
    /// \param target
    /// \param states
    ///
    ////////////////////////////
    void                drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

    ////////////////////////////
    /// \brief Update current node
    ///
    /// \param deltaTime
    ///
    ////////////////////////////
    virtual void        updateCurrent(sf::Time deltaTime);

    ////////////////////////////
    /// \brief Update current node
    ///
    /// \param deltaTime
    ///
    ////////////////////////////
    void                updateChildren(sf::Time deltaTime);

private:

    std::vector<Ptr> m_children;
    SceneNode*       m_parent;

private:

};


#endif //AIRCRAFT_SHOOTER_SCENENODE_HPP
