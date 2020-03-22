#ifndef SPACEINVADERS_GAMEOVERSCENE_H
#define SPACEINVADERS_GAMEOVERSCENE_H

#include "Scene.h"
#include "../UI/Text.h"

namespace SpaceInvaders::Scenes
{
    class GameOverScene : public Scene
    {
    public:
        ~GameOverScene() override;
        void load() override;
    private:

    };
}
#endif
