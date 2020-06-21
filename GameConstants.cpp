#include "GameConstants.h"

int GameConstants::WINDOW_SIZE_X = 1920;
int GameConstants::WINDOW_SIZE_Y = 1080;
bool GameConstants::WINDOW_FULLSCREEN = false;

double GameConstants::SCALE_X = GameConstants::WINDOW_SIZE_X / static_cast<double>(GameConstants::DEFAULT_WINDOW_SIZE_X);
double GameConstants::SCALE_Y = GameConstants::WINDOW_SIZE_Y / static_cast<double>(GameConstants::DEFAULT_WINDOW_SIZE_Y);

uint32_t GameConstants::FPS_TIME = 1000/60;

std::string GameConstants::TEXTURE_PACK = "default";

int GameConstants::MUSIC_VOLUME = 100;
int GameConstants::CLIP_VOLUME = 100;

void GameConstants::recalculate()
{
    GameConstants::SCALE_X = GameConstants::WINDOW_SIZE_X / static_cast<double>(GameConstants::DEFAULT_WINDOW_SIZE_X);
    GameConstants::SCALE_Y = GameConstants::WINDOW_SIZE_Y / static_cast<double>(GameConstants::DEFAULT_WINDOW_SIZE_Y);
}

std::string GameConstants::getAsset(std::string file)
{
    return "texturepacks/" + GameConstants::TEXTURE_PACK + "/" + file;
}
