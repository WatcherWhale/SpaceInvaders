#ifndef SPACEINVADERS_SETTINGS_H
#define SPACEINVADERS_SETTINGS_H

#include <string>
#include <vector>

using namespace std;

class Settings
{
public:
    static Settings load(string filePath);

private:
    Settings(vector<string> settings);
};


#endif
