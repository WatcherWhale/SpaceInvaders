#include "SDLAudioClip.h"
#include "../../../GameConstants.h"

SpaceInvaders::Assets::Audio::SDLAudioClip::SDLAudioClip(std::string path)
{
    Mix_Volume(-1, GameConstants::CLIP_VOLUME);
    this->chunk = Mix_LoadWAV(path.c_str());
}

void SpaceInvaders::Assets::Audio::SDLAudioClip::play()
{
    Mix_PlayChannel(-1, chunk, 0);
}

SpaceInvaders::Assets::Audio::SDLAudioClip::~SDLAudioClip()
{
    Mix_FreeChunk(chunk);
}