///////////////////////////////////////////////////////////////
//  CommandQueue.cpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 01/01/2021                         
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#include "../include/CommandQueue.hpp"

void CommandQueue::push(const Command &command) {
    m_queue.push(command);
}

Command CommandQueue::pop() {

    // Gets the first item in queue
    Command command = m_queue.front();

    // Removes the item in queue
    m_queue.pop();
    return command;
}

bool CommandQueue::isEmpty() const {
    return m_queue.empty();
}
