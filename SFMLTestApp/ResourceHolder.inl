#include "ResourceHolder.h"


template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::Load(Identifier id, const std::string& filename, const Parameter& secondParam)
{
    std::unique_ptr<Resource> resource(new Resource());
    if (!resource->loadFromFile(filename, secondParam))     // secondParam ����� ���� ����������� ��� �������� ��������
        throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));   // ����� ����������� � mResourceMap ����
    assert(inserted.second && "Not insert in mResourceMap!");        // �����������, ��� ������� ��������� ������ � ����
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::Get(Identifier id)
{
    auto found = mResourceMap.find(id);
    assert(found != mResourceMap.end() && "Not found this resource!");    // �����������, ��� ������ found ����� ���� �� id �������
    return *found->second;
}