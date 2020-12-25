///////////////////////////////////////////////////////////////
//  ResourceManager.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 25/12/2020                         
//  Copyright (c) 2020 Yuan Sambo. All rights reserved.     
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
    /// \param Enum id
    /// \param Filename of the resource
    /////////////////////////////////////////
    void                             load(Identifier id,const std::string& filename);

    ////////////////////////////////////////////
    /// \brief Loads resource with two paramaters
    /// \param Enum id
    /// \param Filename of the resource
    /// \param Optional second parameter
    /////////////////////////////////////////////
    template<typename Param>
    void                              load(Identifier id, const std::string& filename, const Param& secondParam);

    //////////////////////////////////////////
    /// \brief Loads resource
    /// \param Enum id
    /// \param Filename of the resource
    /// \return Resource reference
    /////////////////////////////////////////
    Resource&                         get(Identifier id);

    //////////////////////////////////////////
    /// \brief Get function const overload
    /// \param Enum id
    /// \param Filename of the resource
    /// \return Resource reference
    /////////////////////////////////////////
    const Resource&                   get(Identifier id) const;

private:
    std::map<Identifier,
            std::unique_ptr<Resource>>      m_resourceMap;

private:

    //////////////////////////////////////////////
    /// \brief Insert resource to the m_resourceMap
    //////////////////////////////////////////////
    void                              insertResource(Identifier id,std::unique_ptr<Resource> resource);
};

#include "ResourceManager.inl"
#endif  // AIRCRAFT_SHOOTER_RESOURCEMANAGER_HPP
