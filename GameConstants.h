#ifndef GAME_GAMECONSTANTS_H
#define GAME_GAMECONSTANTS_H
#include <cstdint>

const int WINDOW_SIZE_X = 1920;
const int WINDOW_SIZE_Y = 1080;
const bool WINDOW_IS_MAXIMIZED = false;

const int DEFAULT_WINDOW_SIZE_X = 1280;
const int DEFAULT_WINDOW_SIZE_Y = 720;

const int IMPORT_SPRITE_SIZE = 32;
const int DEFAULT_SPRITE_SIZE = 64;
const int SPRITE_SCALE = DEFAULT_SPRITE_SIZE / IMPORT_SPRITE_SIZE;

const double SCALE_X = WINDOW_SIZE_X / static_cast<double>(DEFAULT_WINDOW_SIZE_X);
const double SCALE_Y = WINDOW_SIZE_Y / static_cast<double>(DEFAULT_WINDOW_SIZE_Y);

const uint32_t TIME_30FPS = 1000 / 30;
const uint32_t TIME_60FPS = 1000 / 60;
const uint32_t TIME_120FPS = 1000 / 120;

const double PLAYER_SPEED = 200;
const unsigned long PLAYER_TIMEOUT = 200;

const double BULLET_SPEED = 1000;

const int ENEMIES_X = 6;
const int ENEMIES_Y = 6;
const int ENEMY_SPACING_X = 64;
const int ENEMY_SPACING_Y = -10;
const int ENEMY_OFFSET_Y = 25;
const double ENEMY_SPEED = 100;
const int ENEMY_DELAY_MIN = 500;
const int ENEMY_DELAY_MAX = 2000;

#endif //GAME_GAMECONSTANTS_H
