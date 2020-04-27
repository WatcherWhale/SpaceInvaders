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

        }
        else if(settingKey == "fullscreen")
        {
            //WINDOW_FULLSCREEN = settingValue == "true";
        }
        else if(settingKey == "fps")
        {

        }
    }
}

Settings Settings::load(string path)
{
    ifstream fileStream;
    vector<string> settings;
    string lineStr;

    fileStream.open(path.c_str());

    while(getline(fileStream, lineStr))
    {
        settings.push_back(lineStr);
    }

    return Settings(settings);
}
