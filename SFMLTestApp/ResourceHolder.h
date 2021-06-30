#pragma once
#include <string>
#include <map>
#include <memory>       // std::unique_ptr
#include <cassert>      // assert()
#include "GlobalData.h"
#include <stdexcept>    // std::runtime_error

/*
    ��������� ��������� � �������� ������� (��������, ������, �����)
*/
template <typename Identifier, typename Resource>
class ResourceHolder
{
public:
    /*
        �������� ������� (��������, �����, ����) � mResourceMap �� �����
        \param id - �������������� ������������ �������; filename - �������� ����� �������
    */
    void Load(Identifier id, const std::string& filename);

    /*
        �������� ������� (��������, �����, ����) � mResourceMap �� �����
        \param id - �������������� ������������ �������; filename - �������� ����� �������; secondParam - �������������� ��������
        ��� ������� �������� �������� ��� �������, ��� ���������
    */
    template <typename Parameter>
    void Load(Identifier id, const std::string& filename, const Parameter& secondParam);    

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


#include "ResourceHolder.inl"