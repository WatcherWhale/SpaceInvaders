#ifndef GAME_SCENE_H
#define GAME_SCENE_H


#include <vector>
#include "../GameObjects/GameObject.h"
#include "../UI/UIComponent.h"
#include "../Windows/Window.h"

namespace SpaceInvaders::Scenes
{
    class Scene
    {
    public:
        virtual ~Scene();
        virtual void load() = 0;

        void draw(Windows::Window* win);

        virtual void update(double deltaTime);

    protected:
        std::vector<GameObjects::GameObject*> gameObjects;
        std::vector<UI::UIComponent*> ui;
    };
}
#endif
