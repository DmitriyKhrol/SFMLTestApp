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
        Загрузка ресурса (текстура, шрифт, звук) в mResourceMap из файла
        \param id - индентификатор загружаемого ресурса, filename - название файла ресурса
    */
    template <typename Parameter>
    void Load(Identifier id, const std::string& filename, const Parameter& secondParam);

    /*
        Получение ресурса по его идентификатору
        \param id - идентификатор ресурса, по которому нужно получить ресурс
        \return Возвращает ресурс по его идентификатору
    */
    Resource& Get(Identifier id);
    const Resource& Get(Identifier id) const;
private:
    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};