#include "Scene.h"

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