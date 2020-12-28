///////////////////////////////////////////////////////////////
//  ResourceIdentifiers.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 29/12/2020                         
//  Copyright (c) 2020 Yuan Sambo. All rights reserved.     
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_RESOURCEIDENTIFIERS_HPP
#define AIRCRAFT_SHOOTER_RESOURCEIDENTIFIERS_HPP

//////////////////////////////////////////
/// Contains all the resource identifiers and
/// resource manager typedef for better code
/// readability.
/////////////////////////////////////////

namespace sf{
    class Texture;
    class Font;
}
namespace Textures{
    enum ID{
        Eagle,
        Raptor,
        Desert,
    };
}

namespace Fonts{
    enum ID{
        Sansation,
    };
}

template<typename Resource, typename Identifer>
class ResourceManager;

typedef ResourceManager<sf::Texture,Textures::ID> TextureManager;
typedef ResourceManager<sf::Font,Fonts::ID> FontManager;
#endif //AIRCRAFT_SHOOTER_RESOURCEIDENTIFIERS_HPP
