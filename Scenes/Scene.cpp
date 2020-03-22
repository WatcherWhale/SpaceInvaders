#include "Scene.h"
#include "../Controllers/GameController.h"

SpaceInvaders::Scenes::Scene::~Scene()
{
    for(auto* go : this->gameObjects)
    {
        delete go;
    }

    for(auto* component : this->ui)
    {
        delete component;
    }

    this->gameObjects.clear();
    this->ui.clear();
}

void SpaceInvaders::Scenes::Scene::draw(SpaceInvaders::Windows::Window* win)
{
    for(auto* go : this->gameObjects)
    {
        win->queueSprite(go->getSprite(), go->getPosition(), go->getBounds());
    }

    for(auto* component : this->ui)
    {
        win->queueUI(component);
    }
}

void SpaceInvaders::Scenes::Scene::update(double deltaTime)
{
    for(auto* go1 : this->gameObjects)
    {
        go1->update(deltaTime);

        for(auto* go2 : this->gameObjects)
        {
            if(go1 != go2 && GameObjects::GameObject::checkCollison(go1, go2))
            {
                // Collided
                go1->onCollision(go2);
                go2->onCollision(go1);
            }
        }
    }
}

std::vector<SpaceInvaders::Events::EventListener*>* SpaceInvaders::Scenes::Scene::getListeners()
{
    return &this->eventListeners;
}

void SpaceInvaders::Scenes::Scene::instantiateGameObject(SpaceInvaders::GameObjects::GameObject* go)
{
    go->loadSprites(Controllers::GameController::getInstance().getSpriteLoader());
    this->gameObjects.push_back(go);
}

void SpaceInvaders::Scenes::Scene::lateUpdate()
{

}
