///////////////////////////////////////////////////////////////
//  Player.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 01/01/2021                         
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_PLAYER_HPP
#define AIRCRAFT_SHOOTER_PLAYER_HPP


#include "CommandQueue.hpp"

class Player {
public:
    void            handleEvent(const sf::Event& event, CommandQueue& commands);
    void            handleRealTimeInput(CommandQueue& commands);
};


#endif //AIRCRAFT_SHOOTER_PLAYER_HPP
