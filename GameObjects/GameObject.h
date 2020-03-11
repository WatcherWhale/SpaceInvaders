#ifndef GAME_GAMEOBJECT_H
#define GAME_GAMEOBJECT_H

#include <vector>

#include "../AssetLoaders/Sprites/SpriteLoader.h"

namespace SpaceInvaders::GameObjects
{
    enum GameObjectTag {PLAYER, ENEMY, BULLET, WALL};

    class GameObject
    {
    public:
        GameObject();
        virtual ~GameObject();
        virtual void loadSprites(Assets::Sprites::SpriteLoader* loader) = 0;
        void loadSprites(Assets::Sprites::Sprite* sprite, int amount);
        virtual void update(double deltaTime) = 0;
        virtual void onCollision(GameObject* collided) = 0;

        bool isOutOfScreenY();
        virtual Assets::Sprites::Sprite* getSprite();

        int* getPosition();
        double* getBounds();
        double* getCollider();
        GameObjectTag getTag();

        bool isRemovable();

        static bool checkCollison(GameObject* go1, GameObject* go2);

    protected:
        int position[2];
        double dPosition[2];
        double bounds[4];
        double collider[4];
        int currentSprite = 0;
        std::vector<Assets::Sprites::Sprite*> sprites;
        GameObjectTag tag;

        void move(double dx, double dy);

        bool remove = false;
    private:
        void calculateCollider();
    };
}

#endif //GAME_GAMEOBJECT_H
