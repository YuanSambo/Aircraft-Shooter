///////////////////////////////////////////////////////////////
//  SceneNode.cpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 28/12/2020
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#include "../include/SceneNode.hpp"

SceneNode::SceneNode():m_parent(nullptr) {

}

void SceneNode::attachChild(SceneNode::Ptr child) {

    // Sets this node as the parent of the child
    child->m_parent = this;

    // Pushes the child in the vector
    m_children.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode &node) {

    // Searches the node inside the children vector.
    auto found = std::find_if(m_children.begin(),m_children.end(),
                              // Lambda for matching the corresponding node
                              [&] (Ptr& p) -> bool {return p.get() == &node;});

    //Throws assertion if node is not found
    assert(found != m_children.end());

    // Stores the found node inside the result
    Ptr result = std::move(*found);

    // Sets the parent to null
    result -> m_parent = nullptr;

    // Removes the detached node
    m_children.erase(found);

    //Returns the node
    return result;

}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {

    // Calculates the absolute transform of the node
    states.transform *= getTransform();

    drawCurrent(target, states);
    drawChildren(target,states);
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const {

    // Iterates and draws all children
    for(const Ptr& child : m_children)
        child->draw(target,states);

}

void SceneNode::update(sf::Time deltaTime) {

    updateCurrent(deltaTime);
    updateChildren(deltaTime);
}

void SceneNode::updateCurrent(sf::Time deltaTime) {

}

void SceneNode::updateChildren(sf::Time deltaTime) {

    // Iterates and updates all children
    for(const Ptr& child : m_children)
        child->update(deltaTime);
}

sf::Transform SceneNode::getWorldTransform() const {

    sf::Transform transform = sf::Transform::Identity;

    for(const SceneNode* node = this; node != nullptr ; node = node->m_parent)
        transform *= node->getTransform();

    return transform;
}

sf::Vector2f SceneNode::getWorldPosition() const {
    return getWorldTransform() * sf::Vector2f();
}

