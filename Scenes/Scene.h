#ifndef GAME_SCENE_H
#define GAME_SCENE_H


#include <vector>
#include "../GameObjects/GameObject.h"

namespace SpaceInvaders::Scenes
{
    class Scene
    {
    public:
        virtual GameObjects::GameObject* getGameobjects() = 0;
    };
}
#endif
