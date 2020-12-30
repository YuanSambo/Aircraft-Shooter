///////////////////////////////////////////////////////////////
//  ResourceIdentifiers.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 29/12/2020                         
//  Based on SFML Game Development Book
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

    enum class Textures{
        Eagle,
        Raptor,
        Desert,
    };


    enum class Fonts{
        Sansation,
    };

template<typename Resource, typename Identifer>
class ResourceManager;

typedef ResourceManager<sf::Texture,Textures> TextureManager;
typedef ResourceManager<sf::Font,Fonts> FontManager;
#endif //AIRCRAFT_SHOOTER_RESOURCEIDENTIFIERS_HPP
