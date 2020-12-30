///////////////////////////////////////////////////////////////
//  ResourceManager.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 25/12/2020
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////

#ifndef AIRCRAFT_SHOOTER_RESOURCEMANAGER_HPP
#define AIRCRAFT_SHOOTER_RESOURCEMANAGER_HPP

#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>
#include <memory>
#include <map>

template<typename Resource, typename Identifier>
class ResourceManager {

public:

    //////////////////////////////////////////
    /// \brief Loads resource
    /// \param id
    /// \param Filename
    ///
    /////////////////////////////////////////
    void                             load(Identifier id,const std::string& filename);

    ////////////////////////////////////////////
    /// \brief Loads resource with two parameters
    ///
    /// \param id
    /// \param filename
    /// \param secondParam
    ///
    /////////////////////////////////////////////
    template<typename Param>
    void                              load(Identifier id, const std::string& filename, const Param& secondParam);

    //////////////////////////////////////////
    /// \brief Loads resource
    /// \param id
    /// \return Resource& Reference to the resource
    ///
    /////////////////////////////////////////
    Resource&                         get(Identifier id);

    //////////////////////////////////////////
    /// \brief Get function const overload
    ///
    /// \param id
    /// \return Resource& Reference to the resource
    ///
    /////////////////////////////////////////
    const Resource&                   get(Identifier id) const;

private:
    std::map<Identifier,
            std::unique_ptr<Resource>>      m_resourceMap;

private:
    ///////////////////////////////////////////////
    /// \brief Insert resource to the m_resourceMap
    ///
    /// \param id
    /// \param resource
    ///
    ///////////////////////////////////////////////
    void                              insertResource(Identifier id,std::unique_ptr<Resource> resource);
};

#include "ResourceManager.inl"
#endif  // AIRCRAFT_SHOOTER_RESOURCEMANAGER_HPP
