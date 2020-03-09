#include "Color.h"

Color::Color(uint8_t r, uint8_t g, uint8_t b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

uint8_t Color::getR()
{
    return this->r;
}

uint8_t Color::getG()
{
    return this->g;
}

uint8_t Color::getB()
{
    return this->b;
}

void Color::setR(uint8_t r)
{
    this->r = r;
}

void Color::setG(uint8_t g)
{
    this->g = g;
}

void Color::setB(uint8_t b)
{
    this->b = b;
}