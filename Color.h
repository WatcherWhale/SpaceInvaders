//
// Created by Mathias on 26/02/2020.
//

#ifndef GAME_COLOR_H
#define GAME_COLOR_H

#include <cstdint>

class Color
{
public:
    Color(uint8_t r, uint8_t g, uint8_t b);
    uint8_t getR();
    uint8_t getG();
    uint8_t getB();
    void setR(uint8_t r);
    void setG(uint8_t g);
    void setB(uint8_t b);

private:
    uint8_t r,g,b;
};


#endif //GAME_COLOR_H
