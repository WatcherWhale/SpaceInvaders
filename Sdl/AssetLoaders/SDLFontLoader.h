#ifndef GAME_SDLFONTLOADER_H
#define GAME_SDLFONTLOADER_H

#include "../../AssetLoaders/FontLoader.h"
#include <SDL2/SDL_ttf.h>
#include "../../GameConstants.h"

using namespace SpaceInvaders::Assets;

namespace SDL::Assets
{
    class SDLFontLoader : public FontLoader
    {
    public:
        ~SDLFontLoader() override;
        void loadFont(std::string fontName, std::string path) override;
        void unload() override ;
    };
}

#endif //GAME_SDLFONTLOADER_H
