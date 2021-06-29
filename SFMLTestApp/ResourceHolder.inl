#include "ResourceHolder.h"


template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::Load(Identifier id, const std::string& filename)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename))
        throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));   // Новая вставляемая в mResourceMap пара
    assert(inserted.second && "Not insert in mResourceMap!");        // Утверждение, что удалось поместить ресурс в пару
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::Get(Identifier id)
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end() && "Not found this resource!");    // Утверждение, что индекс found нашёл пару по id ресурса
    return *found->second;
}