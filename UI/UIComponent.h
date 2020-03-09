#ifndef GAME_UICOMPONENT_H
#define GAME_UICOMPONENT_H

namespace SpaceInvaders::UI
{
    class UIComponent
    {
    public:

        virtual void* display() = 0;

        void setPosition(int x, int y);
        void setSize(int w, int h);
        int* getPosition();
        int* getSize();
    protected:
        int position[2];
        int size[2];
    };
}

#endif
