#include "GameConstants.h"

int GameConstants::WINDOW_SIZE_X = 1920;
int GameConstants::WINDOW_SIZE_Y = 1080;
bool GameConstants::WINDOW_FULLSCREEN = false;

double GameConstants::SCALE_X = GameConstants::WINDOW_SIZE_X / static_cast<double>(GameConstants::DEFAULT_WINDOW_SIZE_X);
double GameConstants::SCALE_Y = GameConstants::WINDOW_SIZE_Y / static_cast<double>(GameConstants::DEFAULT_WINDOW_SIZE_Y);

void GameConstants::recalculate()
{
    GameConstants::SCALE_X = GameConstants::WINDOW_SIZE_X / static_cast<double>(GameConstants::DEFAULT_WINDOW_SIZE_X);
    GameConstants::SCALE_Y = GameConstants::WINDOW_SIZE_Y / static_cast<double>(GameConstants::DEFAULT_WINDOW_SIZE_Y);
}
