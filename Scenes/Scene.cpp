#include "Scene.h"
#include "../Controllers/GameController.h"

SpaceInvaders::Scenes::Scene::~Scene()
{
    for(auto* go : this->gameObjects)
    {
        delete go;
    }

    for(auto* ui : this->ui)
    {
        delete ui;
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

    for(auto* ui : this->ui)
    {
        //TODO
    }
}

void SpaceInvaders::Scenes::Scene::update(double deltaTime)
{
    for(auto* go : this->gameObjects)
    {
        go->update(deltaTime);
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
