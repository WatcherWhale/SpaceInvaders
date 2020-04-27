#ifndef GAME_GAMECONSTANTS_H
#define GAME_GAMECONSTANTS_H
#include <cstdint>

class GameConstants
{
public:
    static void recalculate();

    static int WINDOW_SIZE_X;
    static int WINDOW_SIZE_Y;
    static bool WINDOW_FULLSCREEN;

    static const int DEFAULT_WINDOW_SIZE_X = 1280;
    static const int DEFAULT_WINDOW_SIZE_Y = 720;

    static const int IMPORT_SPRITE_SIZE = 32;
    static const int DEFAULT_SPRITE_SIZE = 64;
    static const int SPRITE_SCALE = DEFAULT_SPRITE_SIZE / IMPORT_SPRITE_SIZE;

    static double SCALE_X;
    static double SCALE_Y;

    static uint32_t FPS_TIME;

    constexpr static const double PLAYER_SPEED = 200;
    static const unsigned long PLAYER_TIMEOUT = 500;

    constexpr static const double BULLET_SPEED = 1000;

    static const int ENEMIES_X = 6;
    static const int ENEMIES_Y = 6;
    static const int ENEMY_SPACING_X = 64;
    static const int ENEMY_SPACING_Y = -10;
    static const int ENEMY_OFFSET_Y = 25;
    constexpr static const double ENEMY_SPEED = 100;
    static const int ENEMY_DELAY_MIN = 500;
    static const int ENEMY_DELAY_MAX = 2000;
    static const int BONUS_DELAY_MIN = 10000;
    static const int BONUS_DELAY_MAX = 20000;
};

#endif //GAME_GAMECONSTANTS_H
