#ifndef SPACEINVADERS_AUDIOCLIP_H
#define SPACEINVADERS_AUDIOCLIP_H

namespace SpaceInvaders::Assets::Audio
{
    class AudioClip
    {
    public:
        virtual ~AudioClip() = default;
        virtual void play() = 0;
    };
}
#endif
