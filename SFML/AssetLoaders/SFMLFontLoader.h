#ifndef SPACEINVADERS_SFMLFONTLOADER_H
#define SPACEINVADERS_SFMLFONTLOADER_H

#include "../../AssetLoaders/FontLoader.h"
#include "../../GameConstants.h"

using namespace SpaceInvaders::Assets;

namespace SFML::Assets
{
    class SFMLFontLoader : public FontLoader
    {
    public:
        ~SFMLFontLoader() override;
        void loadFont(std::string fontName, std::string path) override;
        void unload() override ;
    };
}

#endif
