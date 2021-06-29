#pragma once
#include <string>
#include <map>
#include <memory>
#include <cassert>
#include "GlobalData.h"

template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
    /*
        �������� ������� (��������, ������ � ��.) � mResourceMap �� �����
        \param id - �������������� ������������ �������, filename - �������� ����� �������
    */
    void Load(Identifier id, const std::string& filename);

    /*
        ��������� ������� �� ��� ��������������
        \param id - ������������� �������, �� �������� ����� �������� ������
        \return ���������� ������ �� ��� ��������������
    */
    Resource& Get(Identifier id);
    const Resource& Get(Identifier id) const;
private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};