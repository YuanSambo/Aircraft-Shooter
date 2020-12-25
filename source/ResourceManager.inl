///////////////////////////////////////////////////////////////
//  ResourceManager.inl
//  SFML_ShootEmUp
//
//  Created by Yuan Sambo on 25/12/2020
//  Copyright (c) 2020 Yuan Sambo All rights reserved.
////////////////////////////////////////////////////////////////


#include "ResourceManager.hpp"

template<typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::load(Identifier id, const std::string &filename) {

    // Loads new resource.
    std::unique_ptr<Resource> resource(new Resource());

    // Loads the filename and throws exception if it fails.
    if (!resource->loadFromFile(filename))
        throw std::runtime_error("ResourceManager::load - Failed to load" + filename);

    insertResource(id,std::move(resource));
}

template<typename Resource, typename Identifier>
template<typename Param>
void ResourceManager<Resource, Identifier>::load(Identifier id, const std::string &filename, const Param &secondParam) {

    // Loads new resource.
    std::unique_ptr<Resource> resource(new Resource());

    // Loads the filename and throws exception if it fails.
    if (!resource->loadFromFile(filename,secondParam))
        throw std::runtime_error("ResourceManager::load - Failed to load" + filename);

    insertResource(id,std::move(resource));

}

template<typename Resource, typename Identifier>
Resource &ResourceManager<Resource, Identifier>::get(Identifier id) {

    // Find the id inside the m_resourceMap.
    auto found = m_resourceMap.find(id);

    //Throws assertion if id not found.
    assert(found != m_resourceMap.end());

    // Returns the resource
    return *found->second;
}

template<typename Resource, typename Identifier>
const Resource &ResourceManager<Resource, Identifier>::get(Identifier id) const {

    // Find the id inside the m_resourceMap.
    auto found = m_resourceMap.find(id);

    //Throws assertion if id not found.
    assert(found != m_resourceMap.end());

    // Returns the resource
    return *found->second;

}

template<typename Resource, typename Identifier>
void ResourceManager<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource) {

    // Inserts pair of id and Resource into the m_resourceMap.
    auto inserted = m_resourceMap.insert(std::make_pair(id, std::move(resource)));

    // Throws assertion if the insertion failed.
    assert(inserted.second);
}

