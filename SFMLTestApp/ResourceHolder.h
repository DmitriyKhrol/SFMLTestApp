#pragma once
#include <string>
#include <map>
#include <memory>
#include <cassert>
#include "GlobalData.h"

template <typename Identifier, typename Resource>
class ResourceHolder
{
public:
    /*
        Загрузка ресурса (текстура, шрифт, звук) в mResourceMap из файла
        \param id - индентификатор загружаемого ресурса; filename - название файла ресурса
    */
    void Load(Identifier id, const std::string& filename);

    /*
        Загрузка ресурса (текстура, шрифт, звук) в mResourceMap из файла
        \param id - индентификатор загружаемого ресурса; filename - название файла ресурса; secondParam - дополнительный параметр
        для функций загрузки шейдеров или текстур, где необходим
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


#include "ResourceHolder.inl"