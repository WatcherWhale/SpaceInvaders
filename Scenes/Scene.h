#ifndef GAME_SCENE_H
#define GAME_SCENE_H


#include <vector>
#include "../Factories/Factory.h"
#include "../GameObjects/GameObject.h"
#include "../UI/UIComponent.h"
#include "../Windows/Window.h"

namespace SpaceInvaders::Scenes
{
    class Scene
    {
    public:
        virtual ~Scene();
        virtual void load(Factories::GameFactory* factory, Assets::Sprites::SpriteLoader* loader) = 0;

        virtual void draw(Windows::Window* win);

        virtual void update(double deltaTime);

        std::vector<Events::EventListener*>* getListeners();

    protected:
        std::vector<GameObjects::GameObject*> gameObjects;
        std::vector<UI::UIComponent*> ui;
        std::vector<Events::EventListener*> eventListeners;
    };
}
#endif
