#ifndef GAME_FONTLOADER_H
#define GAME_FONTLOADER_H

#include <map>

namespace SpaceInvaders::Assets
{
    class FontLoader
    {
    public:
        virtual ~FontLoader();
        virtual void loadFont(std::string fontName, std::string path) = 0;
        virtual void unload() = 0;
        void* getFont(std::string fontName);


    protected:
        std::map<std::string, void*> fonts;
    };
}


#endif //GAME_FONTLOADER_H
