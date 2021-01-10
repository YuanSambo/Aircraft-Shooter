///////////////////////////////////////////////////////////////
//  Command.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 01/01/2021                         
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_COMMAND_HPP
#define AIRCRAFT_SHOOTER_COMMAND_HPP

#include "SFML/Graphics.hpp"
class SceneNode;

struct Command{
                                              Command();
    std::function<void(SceneNode&, sf::Time)> action;
    unsigned int                              category;
};

template<typename GameObject, typename Function>
std::function<void(SceneNode&,sf::Time)> derivedAction (Function fn){

    return [=] (SceneNode& node,sf::Time deltaTime){

            assert(dynamic_cast<GameObject*>(&node) != nullptr);

            fn(static_cast<GameObject&>(node),deltaTime);
    };
}


#endif //AIRCRAFT_SHOOTER_COMMAND_HPP
