#include "Settings.h"
#include "GameConstants.h"
#include <fstream>
#include <iostream>

Settings::Settings(vector<string> settings)
{
    for (string setting : settings)
    {
        int pos = setting.find_first_of(':');

        string settingKey = setting.substr(0, pos);
        string settingValue = setting.substr(pos + 1);

        if(settingKey == "resolution")
        {
            int xPos = settingValue.find_first_of('x');
            string width = settingValue.substr(0,xPos);
            string height = settingValue.substr(xPos + 1);

            GameConstants::WINDOW_SIZE_X = atoi(width.c_str());
            GameConstants::WINDOW_SIZE_Y = atoi(height.c_str());

            GameConstants::recalculate();
        }
        else if(settingKey == "fullscreen")
        {
            GameConstants::WINDOW_FULLSCREEN = settingValue == "true";
        }
        else if(settingKey == "fps")
        {
            GameConstants::FPS_TIME = 1000 / atoi(settingValue.c_str());
        }
        else if(settingKey == "volume")
        {
            GameConstants::MUSIC_VOLUME = atoi(settingValue.c_str());
        }
        else if(settingKey == "sfxvolume")
        {
            GameConstants::CLIP_VOLUME = atoi(settingValue.c_str());
        }
        else if(settingKey == "texturepack")
        {
            GameConstants::TEXTURE_PACK = settingValue;
        }
    }
}

Settings Settings::load(string path)
{
    ifstream fileStream;
    vector<string> settings;
    string lineStr;

    fileStream.open(path.c_str());

    getline(fileStream, lineStr);

    while(getline(fileStream, lineStr))
    {
        settings.push_back(lineStr);
    }

    return Settings(settings);
}
