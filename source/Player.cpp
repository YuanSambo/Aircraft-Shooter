///////////////////////////////////////////////////////////////
//  Player.cpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 01/01/2021                         
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#include "../include/Player.hpp"
#include "../include/Aircraft.hpp"
#include "../include/Category.hpp"

struct AircraftMover{
     sf:: Vector2f velocity;

    AircraftMover(float vx, float vy) : velocity(vx,vy){

        }

        void operator () ( Aircraft& aircraft, sf::Time) const{

            aircraft.accelerate(velocity);

        }

};


Player::Player() {

    // Set initial key bindings
    m_keyBinding[sf::Keyboard::Left] = MoveLeft;
    m_keyBinding[sf::Keyboard::Right] = MoveRight;
    m_keyBinding[sf::Keyboard::Up] = MoveUp;
    m_keyBinding[sf::Keyboard::Down] = MoveDown;

    // Set initial action bindings
    initializeActions();

    // Assign all categories to player's aircraft
    for(auto& pair :  m_actionBinding)
    pair.second.category = Category::PlayerAircraft;
}


void Player::handleEvent(const sf::Event &event, CommandQueue &commands) {
    if (event.type == sf::Event::KeyPressed)
    {
        // Check if pressed key appears in key binding, trigger command if so
        auto found = m_keyBinding.find(event.key.code);
        if (found != m_keyBinding.end() && !isRealtimeAction(found->second))
            commands.push(m_actionBinding[found->second]);
    }
}

void Player::handleRealTimeInput(CommandQueue &commands) {

    // Traverse all assigned keys and check if they are pressed
    for(auto pair : m_keyBinding)
    {
        // If key is pressed, lookup action and trigger corresponding command
        if (sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second))
           commands.push(m_actionBinding[pair.second]);
    }
}

void Player::assignKey(Player::Action action, sf::Keyboard::Key key) {

    // Remove all keys that already map to action
    for (auto itr = m_keyBinding.begin(); itr != m_keyBinding.end(); )
    {
        if (itr->second == action)
            m_keyBinding.erase(itr++);
        else
            ++itr;
    }

    // Insert new binding
    m_keyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Player::Action action) const {

    for(auto pair : m_keyBinding){
            if(pair.second == action)
                return pair.first;
    }

    return sf::Keyboard::Unknown;
}

void Player::initializeActions() {
    const float playerSpeed = 200.f;

    m_actionBinding[MoveLeft].action  = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
    m_actionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(+playerSpeed, 0.f));
    m_actionBinding[MoveUp].action    = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
    m_actionBinding[MoveDown].action  = derivedAction<Aircraft>(AircraftMover(0.f, +playerSpeed));
}

bool Player::isRealtimeAction(Player::Action action) {

    switch (action)
    {
        case MoveLeft:
        case MoveRight:
        case MoveDown:
        case MoveUp:
            return true;

        default:
            return false;
    }
}
