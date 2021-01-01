///////////////////////////////////////////////////////////////
//  CommandQueue.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 01/01/2021                         
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_COMMANDQUEUE_HPP
#define AIRCRAFT_SHOOTER_COMMANDQUEUE_HPP


#include <queue>
#include "Command.hpp"

class CommandQueue {
public:
    void            push(const Command& command);
    Command         pop();
    bool            isEmpty() const;

private:
    std::queue<Command> m_queue;
};


#endif //AIRCRAFT_SHOOTER_COMMANDQUEUE_HPP
