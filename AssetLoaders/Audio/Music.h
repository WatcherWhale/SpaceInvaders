#ifndef SPACEINVADERS_MUSIC_H
#define SPACEINVADERS_MUSIC_H

namespace SpaceInvaders::Assets::Audio
{
    class Music
    {
    public:
        virtual ~Music() = default;
        virtual void play(bool loop) = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;
    };
}
#endif
