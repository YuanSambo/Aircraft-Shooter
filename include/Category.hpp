///////////////////////////////////////////////////////////////
//  Category.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 01/01/2021                         
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_CATEGORY_HPP
#define AIRCRAFT_SHOOTER_CATEGORY_HPP


namespace Category{
    enum Type{
        None            = 0,
        Scene           = 1 << 0,
        PlayerAircraft  = 1 << 1,
        AlliedAircraft  = 1 << 2,
        EnemyAircraft   = 1 << 3,

    };
}

#endif //AIRCRAFT_SHOOTER_CATEGORY_HPP
