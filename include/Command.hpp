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


#endif //AIRCRAFT_SHOOTER_COMMAND_HPP
