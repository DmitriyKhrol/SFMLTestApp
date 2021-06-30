#include "ResourceHolder.h"


template <typename Identifier, typename Resource>
void ResourceHolder<Identifier, Resource>::Load(Identifier id, const std::string& filename)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename))
        throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));   // ����� ����������� � mResourceMap ����
    assert(inserted.second && "Not insert in mResourceMap!");        // �����������, ��� ������� ��������� ������ � ����
}

template <typename Identifier, typename Resource>
template <typename Parameter>
void ResourceHolder<Identifier, Resource>::Load(Identifier id, const std::string& filename, const Parameter& secondParam)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename, secondParam))     // secondParam ����� ���� ����������� ��� �������� ��������
        throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));   // ����� ����������� � mResourceMap ����
    assert(inserted.second && "Not insert in mResourceMap!");        // �����������, ��� ������� ��������� ������ � ����
}

template <typename Identifier, typename Resource>
Resource& ResourceHolder<Identifier, Resource>::Get(Identifier id)
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end() && "Not found this resource!");    // �����������, ��� ������ found ����� ���� �� id �������
    return *found->second;
}