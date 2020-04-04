#ifndef GAME_UICOMPONENT_H
#define GAME_UICOMPONENT_H

namespace SpaceInvaders::UI
{
    typedef struct
    {
        void* texture;
        double* size;
        int* position;
    } UISpriteContainer;

    class UIComponent
    {
    public:
        UIComponent(int x, int y);
        UIComponent(int x, int y, double w, double h);
        virtual ~UIComponent() = default;

        virtual UISpriteContainer display() = 0;
        virtual bool doneDisplaying() { return true; };

        void scale(double f);
        void scale(double x, double y);

        void setPosition(int x, int y);
        void setSize(double w, double h);
        int* getPosition();
        double* getSize();

    protected:
        int position[2];
        double size[2];
    };
}

#endif
