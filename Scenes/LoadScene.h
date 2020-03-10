#ifndef SPACEINVADERS_LOADSCENE_H
#define SPACEINVADERS_LOADSCENE_H

#include "Scene.h"
#include <future>

namespace SpaceInvaders::Scenes
{
    class LoadScene : public Scene
    {
    public:
        void update(double deltaTime) override;
        void load() override;
        void draw(Windows::Window* window) override;
        void addProgress();
    private:
        int progress = 0;
        int maxProgress = 2;
        bool loaded = false;
        std::future<void> loadThread;
    };
}

void loadAssetsAsync(SpaceInvaders::Scenes::LoadScene* loadScene);
#endif
