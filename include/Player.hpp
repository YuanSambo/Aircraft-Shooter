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
    enum Action {
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown,
        ActionCount
    };
public:
                    Player();
    void            handleEvent(const sf::Event& event, CommandQueue& commands);
    void            handleRealTimeInput(CommandQueue& commands);
    void               assignKey(Action action, sf::Keyboard::Key key);
    sf::Keyboard::Key   getAssignedKey(Action action) const;


private:
    void            initializeActions();
    static bool     isRealtimeAction(Action action);

private:
    std::map<sf::Keyboard::Key,Action>      m_keyBinding;
    std::map<Action,Command>               m_actionBinding;
};


#endif //AIRCRAFT_SHOOTER_PLAYER_HPP
