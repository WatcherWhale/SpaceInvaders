#include <fstream>
#include <utility>
#include "JsonFile.h"

SpaceInvaders::Utils::JsonFile::JsonFile(std::string path, json j)
{
    this->jsonObject = std::move(j);
}

SpaceInvaders::Utils::JsonFile SpaceInvaders::Utils::JsonFile::load(std::string path)
{
    std::ifstream file(path.c_str());
    json j = json::parse(file);
    return JsonFile(path, j);
}

void SpaceInvaders::Utils::JsonFile::Save()
{
    std::ofstream file(path.c_str());
    file << this->jsonObject;
}

std::string SpaceInvaders::Utils::JsonFile::getString(std::string key)
{
    return this->jsonObject.at(key);
}

int SpaceInvaders::Utils::JsonFile::getInt(std::string key)
{
    return this->jsonObject.at(key);
}

json* SpaceInvaders::Utils::JsonFile::getObject(std::string key)
{
    return &this->jsonObject.at(key);
}
