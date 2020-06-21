#ifndef SPACEINVADERS_JSONFILE_H
#define SPACEINVADERS_JSONFILE_H

#include "../json.hpp"
using json = nlohmann::json;

namespace SpaceInvaders::Utils
{
    class JsonFile
    {
    public:
        void Save();
        static JsonFile load(std::string path);
        std::string getString(std::string key);
        int getInt(std::string key);
        json* getObject(std::string key);

    private:
        JsonFile(std::string path, json j);
        json jsonObject;
        std::string path;
    };
}

#endif
